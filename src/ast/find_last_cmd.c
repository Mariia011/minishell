/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:10:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast_node	*dfs(t_ast_node *root);

t_ast_node	*find_last_cmd(t_ast *ast)
{
	return (dfs(ast->root));
}

static t_ast_node	*dfs(t_ast_node *root)
{
	t_ast_node	*curr;
	t_ast_node	*l;
	t_ast_node	*r;

	if (!root)
		return (NULL);
	curr = NULL;
	l = NULL;
	r = NULL;
	if (root->type == CMD)
		curr = root;
	r = dfs(root->right);
	if (r)
		return (r);
	if (curr)
		return (curr);
	l = dfs(root->left);
	return (l);
}
