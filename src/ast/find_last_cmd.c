/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 18:55:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast_node	*dfs(t_ast_node *root);

t_ast_node	*find_last_cmd(t_ast *ast)
{
	return dfs(ast->root);
}

static t_ast_node	*dfs(t_ast_node *root)
{
	if (!root) return NULL;

	t_ast_node	*curr = NULL;
	t_ast_node	*l = NULL;
	t_ast_node	*r = NULL;

	if (root->type == CMD)
		curr = root;

	r = dfs(root->right);

	if (r) return r;

	if (curr) return curr;

	l = dfs(root->left);

	return l;
}

