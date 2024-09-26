/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:01:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 03:47:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ast_rrotate(t_ast *ast, t_ast_node *x, t_ast_node *z)
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

		if (x == x->p->right)
			x->p->right = z;
		else
			x->p->left = z;
	}
	x->p = z;
	w->left = z->right;
	z->right->p = w;
	z->right = x;
}
