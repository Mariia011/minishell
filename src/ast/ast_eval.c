/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 02:38:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int dfs(t_ast_node *root, t_ast *ast);

void ast_eval(t_ast *ast)
{
	dfs(ast->root, ast);
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
	else if (root->type == CMD)
	{
		root->cmd_ptr->eval(root->cmd_ptr);

		if (root == ast->last_process_cmd)
			while (-1 != wait(NULL));

		return !get_exit_status();
	}
	abort();
}

