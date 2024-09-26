/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_by_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:35:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 03:12:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast_node	*dfs(t_ast_node *root, t_node * token);

t_ast_node *ast_find_by_token(t_ast * ast, t_node *token)
{
	return dfs(ast->root, token);
}

static t_ast_node	*dfs(t_ast_node *root, t_node * token)
{
	if (!root || !token) return NULL;

	t_ast_node	*l = NULL;
	t_ast_node	*r = NULL;

	if (root->orig_token == token)
		return root;

	r = dfs(root->right, token);

	if (r) return r;

	return dfs(root->left, token);
}
