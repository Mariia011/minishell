/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 17:52:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int dfs(t_ast_node *root, t_ast *ast, t_authorized_fds fds);

void ast_eval(t_ast *ast) // ls | (cat 12345 && echo hello)
{
	if (!ast)
		return;

	t_authorized_fds fds;

	fds.stdin.fd = ast->shell->stddesc->stdin;
	fds.stdin.author = NULL;
	fds.stdout.fd = ast->shell->stddesc->stdout;
	fds.stdout.author = NULL;

	dfs(ast->root, ast, fds);

	while (-1 != wait(NULL));

	dup2(ast->shell->stddesc->stdin, STDIN_FILENO);
	dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);
	dup2(ast->shell->stddesc->stderr, STDERR_FILENO);
}

static int dfs(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	if  (!root) return 1;

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
		t_fd	pipes[PIPE_MAX];

		pipe(pipes);

		dup2(pipes[out], STDOUT_FILENO);

		t_authorized_fds new_fds;

		new_fds.stdin = fds.stdin;
		new_fds.stdout.fd = pipes[out];
		new_fds.stdout.author = root;

		dfs(root->left, ast, new_fds);

		dup2(pipes[in], STDIN_FILENO);

		close(pipes[in]);
		close(pipes[out]);

		dup2(fds.stdout.fd, STDOUT_FILENO);

		int y = dfs(root->right, ast, fds);

		t_ast_node *last = find_last_process_cmd(root->right);

		if ((!root->p || root->p->type == AND || root->p->type == OR) && last)
		{
			pid_t x = 0;
			waitpid(last->cmd_ptr->pid, &x, 0);
			set_exit_status(WEXITSTATUS(x));
			return !get_exit_status();
		}
		return y;
	}
	else if (root->type == CMD)
	{
		if (root->p && root->p->type == PIPE)
			root->cmd_ptr->forkable = true;

		cmd_runtime_init(root->cmd_ptr);
		root->cmd_ptr->eval(root->cmd_ptr);

		if ((!root->p || root->p->type == AND || root->p->type == OR) && is_program(root->cmd_ptr))
		{
			pid_t x = 0;
			waitpid(root->cmd_ptr->pid, &x, 0);
			set_exit_status(WEXITSTATUS(x));
		}

		return !get_exit_status();
	}

	else // if (root->type == REDIRECTION)
	{
		t_authorized_fds new_fds = redirect(root, fds);

		return dfs(root->left, ast, new_fds);
	}
}

