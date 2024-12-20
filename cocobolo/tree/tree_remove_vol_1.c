/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove_vol_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:42:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:08:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	transplant(t_tree *tree, t_tree_node *u, t_tree_node *v)
{
	if (!tree)
		return ;
	if (u->p == tree->nil)
		tree->root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

static t_color	delete_2_child_case(t_tree *tree, t_tree_node *z,
		t_tree_node **x, t_tree_node **y)
{
	t_color	y_orig_color;

	(*y) = __find_min__(tree, z->right);
	y_orig_color = (*y)->color;
	(*x) = (*y)->right;
	if ((*y)->p == z)
		(*x)->p = (*y);
	else
	{
		transplant(tree, (*y), (*y)->right);
		(*y)->right = z->right;
		(*y)->right->p = (*y);
	}
	transplant(tree, z, (*y));
	(*y)->left = z->left;
	(*y)->left->p = (*y);
	(*y)->color = z->color;
	return (y_orig_color);
}

static void	_delete(t_tree *tree, t_tree_node *z)
{
	t_tree_node	*x;
	t_tree_node	*y;
	t_color		y_orig_color;

	x = tree->nil;
	y = z;
	y_orig_color = y->color;
	if (z->left == tree->nil)
	{
		x = z->right;
		transplant(tree, z, z->right);
	}
	else if (z->right == tree->nil)
	{
		x = z->left;
		transplant(tree, z, z->left);
	}
	else
		y_orig_color = delete_2_child_case(tree, z, &x, &y);
	delete_node(z);
	z = NULL;
	if (y_orig_color == BLACK)
		_delete_fixup(tree, x);
}

void	tree_remove(t_tree *tree, t_treeval key)
{
	t_tree_node	*z;

	if (!tree)
		return ;
	z = tree_find(tree, key);
	if (z != tree->nil)
		_delete(tree, z);
}
