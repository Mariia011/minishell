/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_lrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:55:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 03:48:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ast_lrotate(t_ast *ast, t_ast_node *x, t_ast_node *z)
{
	if (!ast || !x || !z)
		return;
	t_ast_node *w = z->p;
	if (x == ast->root)
	{
		ast->root = z;
		z->p = NULL;
	}
	else
	{
		z->p = x->p;

		if (x == x->p->left)
			x->p->left = z;
		else
			x->p->right = z;
	}
	x->p = z;
	w->right = z->left;
	z->left->p = w;
	z->left = x;
}
