/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 19:40:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int dfs(t_ast_node *root, t_ast *ast, int stdout);

void ast_eval(t_ast *ast)
{
	if (!ast)
		return;

	dfs(ast->root, ast, ast->shell->stddesc->stdout);

	while (-1 != wait(NULL));

	dup2(ast->shell->stddesc->stdin, STDIN_FILENO);
	dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);
	dup2(ast->shell->stddesc->stderr, STDERR_FILENO);
}

static int dfs(t_ast_node *root, t_ast *ast, int stdout)
{
	if  (!root) return 1;

	if (root->type == AND)
	{
		return (dfs(root->left, ast, stdout) && dfs(root->right, ast, stdout));
	}
	else if (root->type == OR)
	{
		return (dfs(root->left, ast, stdout) || dfs(root->right, ast, stdout));
	}
	else if (root->type == PIPE)
	{
		t_fd	pipes[PIPE_MAX];

		pipe(pipes);

		dup2(pipes[out], STDOUT_FILENO);

		dfs(root->left, ast, pipes[out]);

		dup2(pipes[in], STDIN_FILENO);

		close(pipes[in]);
		close(pipes[out]);

		dup2(stdout, STDOUT_FILENO);

		int x = dfs(root->right, ast, stdout);

		if (!root->p || root->p->type == AND || root->p->type == OR)
			while (-1 != wait(NULL));

		return x;
	}
	else if (root->type == CMD)
	{
		// if (root->p && root->p->type == PIPE)
		// 	root->cmd_ptr->forkable = true;

		root->cmd_ptr->eval(root->cmd_ptr);

		if ((!root->p || root->p->type == AND || root->p->type == OR) && is_program(root->cmd_ptr))
		{
			pid_t x = 0;
			waitpid(root->cmd_ptr->pid, &x, 0);
			set_exit_status(WEXITSTATUS(x));
		}

		return !get_exit_status();
	}
	__exit("not handled yet:)");
}

