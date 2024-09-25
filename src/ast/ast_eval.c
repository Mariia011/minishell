/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 23:15:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int dfs(t_ast_node *root, t_ast *ast);

void ast_eval(t_ast *ast)
{
	dfs(ast->root, ast);

	dup2(ast->shell->stddesc->stdin, STDIN_FILENO);
	dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);
	dup2(ast->shell->stddesc->stderr, STDERR_FILENO);
}

static int dfs(t_ast_node *root, t_ast *ast)
{
	if (!root) return 1;

	if (root->type == AND)
	{
		return (dfs(root->left, ast) && dfs(root->right, ast));
	}
	else if (root->type == OR)
	{
		return (dfs(root->left, ast) || dfs(root->right, ast));
	}
	else if (root->type == PIPE)
	{
		t_fd	pipes[PIPE_MAX];

		pipe(pipes);

		dup2(pipes[out], STDOUT_FILENO);

		dup2(pipes[in], STDIN_FILENO);

		dfs(root->left, ast);

		close(pipes[in]);
		close(pipes[out]);

		if (!root->p || root->p->type != PIPE)
			dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);

		return dfs(root->right, ast);
	}
	else if (root->type == CMD)
	{
		root->cmd_ptr->eval(root->cmd_ptr);

		if (!root->p || root->p->type == PIPE || is_program(root->cmd_ptr))
			while (-1 != wait(NULL));

		return !get_exit_status();
	}
	__exit("not handled yet:)");
}

