/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_by_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:35:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 11:11:56 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast_node	*dfs(t_ast_node *root, t_listnode *token);

t_ast_node	*ast_find_by_token(t_ast *ast, t_listnode *token)
{
	return (dfs(ast->root, token));
}

static t_ast_node	*dfs(t_ast_node *root, t_listnode *token)
{
	t_ast_node	*r;

	if (!root || !token)
		return (NULL);
	r = NULL;
	if (root->orig_token == token)
		return (root);
	r = dfs(root->right, token);
	if (r)
		return (r);
	return (dfs(root->left, token));
}
