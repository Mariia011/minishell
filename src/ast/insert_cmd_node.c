/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:29:51 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 01:32:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void insert_cmd_node(t_ast *ast, t_ast_node *z)
{
	t_ast_node *x = ast->root;

	while (x && x->left && x->right)
		x = x->left;

	if (x == NULL)
	{
		ast->root = z;
	}
	else if (!x->right)
	{
		x->right = z;
		z->p = x;
	}
	else
	{
		x->left = z;
		z->p = x;
	}
}
