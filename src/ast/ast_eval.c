/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 19:27:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dfs(t_ast_node *root, t_ast *ast, t_authorized_fds fds);
static int	ast_handle_pipe(t_ast_node *root, t_ast *ast, t_authorized_fds fds);
static int	ast_handle_cmd(t_ast_node *root, t_ast *ast, t_authorized_fds fds);

void	ast_eval(t_ast *ast) // ls | (cat 12345 && echo hello)
{
	t_authorized_fds	fds;

	if (!ast)
		return ;
	fds.stdin.fd = ast->shell->stddesc->stdin;
	fds.stdin.author = NULL;
	fds.stdout.fd = ast->shell->stddesc->stdout;
	fds.stdout.author = NULL;
	dfs(ast->root, ast, fds);
	while (-1 != wait(NULL))
		;
	dup2(ast->shell->stddesc->stdin, STDIN_FILENO);
	dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);
	dup2(ast->shell->stddesc->stderr, STDERR_FILENO);
}

static int	dfs(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	if (!root)
		return (1);
	if (root->type == AND)
	{
		return (dfs(root->left, ast, fds) && dfs(root->right, ast, fds));
	}
	else if (root->type == OR)
	{
		return (dfs(root->left, ast, fds) || dfs(root->right, ast, fds));
	}
	else if (root->type == PIPE)
	{
		return (ast_handle_pipe(root, ast, fds));
	}
	else if (root->type == CMD)
	{
		return (ast_handle_cmd(root, ast, fds));
	}
	else // if (root->type == REDIRECTION)
	{
		return (dfs(root->left, ast, redirect(root, fds)));
	}
}

static int	ast_handle_pipe(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	t_fd				pipes[PIPE_MAX];
	t_authorized_fds	new_fds;
	int					y;
	t_ast_node			*last;
	pid_t				x;

	pipe(pipes);
	dup2(pipes[out], STDOUT_FILENO);
	new_fds.stdin = fds.stdin;
	new_fds.stdout.fd = pipes[out];
	new_fds.stdout.author = root;
	dfs(root->left, ast, new_fds);
	if (!root->p || root->p->type != REDIRECTION)
		dup2(pipes[in], STDIN_FILENO);
	__va_close(&pipes[in], &pipes[out], NULL);
	dup2(fds.stdout.fd, STDOUT_FILENO);
	y = dfs(root->right, ast, fds);
	last = find_last_process_cmd(root->right);
	if ((!root->p || root->p->type == AND || root->p->type == OR) && last)
	{
		waitpid(last->cmd_ptr->pid, &x, 0);
		set_exit_status(WEXITSTATUS(x));
		return (!get_exit_status());
	}
	return (y);
}

static int	ast_handle_cmd(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	pid_t	x;

	if (root->p && root->p->type == PIPE)
		root->cmd_ptr->forkable = true;
	cmd_runtime_init(root->cmd_ptr);
	root->cmd_ptr->eval(root->cmd_ptr);
	if ((!root->p || root->p->type == AND || root->p->type == OR)
		&& is_program(root->cmd_ptr))
	{
		x = 0;
		waitpid(root->cmd_ptr->pid, &x, 0);
		set_exit_status(WEXITSTATUS(x));
	}
	return (!get_exit_status());
}
