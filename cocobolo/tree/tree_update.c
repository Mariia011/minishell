/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:07:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:09:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__left_case__(t_tree *tree, t_tree_node **z)
{
	t_tree_node	*y;

	y = (*z)->p->p->right;
	if (y->color == RED)
	{
		y->color = BLACK;
		(*z)->p->color = BLACK;
		(*z)->p->p->color = RED;
		(*z) = (*z)->p->p;
	}
	else
	{
		if ((*z) == (*z)->p->right)
		{
			(*z) = (*z)->p;
			left_rotate(tree, (*z));
		}
		(*z)->p->color = BLACK;
		(*z)->p->p->color = RED;
		right_rotate(tree, (*z)->p->p);
	}
}

static void	__right_case__(t_tree *tree, t_tree_node **z)
{
	t_tree_node	*y;

	y = (*z)->p->p->left;
	if (y->color == RED)
	{
		y->color = BLACK;
		(*z)->p->color = BLACK;
		(*z)->p->p->color = RED;
		(*z) = (*z)->p->p;
	}
	else
	{
		if ((*z) == (*z)->p->left)
		{
			(*z) = (*z)->p;
			right_rotate(tree, (*z));
		}
		(*z)->p->color = BLACK;
		(*z)->p->p->color = RED;
		left_rotate(tree, (*z)->p->p);
	}
}

static void	_insert_fixup(t_tree *tree, t_tree_node *z)
{
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
			__left_case__(tree, &z);
		else
			__right_case__(tree, &z);
	}
	tree->root->color = BLACK;
}

static void	_insert(t_tree *tree, t_tree_node *z)
{
	t_tree_node	*y;
	t_tree_node	*x;

	y = tree->nil;
	x = tree->root;
	while (x != tree->nil)
	{
		y = x;
		if (tree->less(z->key, x->key))
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if (y == tree->nil)
		tree->root = z;
	else if (tree->less(z->key, y->key))
		y->left = z;
	else
		y->right = z;
	_insert_fixup(tree, z);
}

void	tree_update(t_tree *tree, t_treeval key, t_treeval val)
{
	if (!tree)
		return ;
	tree_remove(tree, key);
	_insert(tree, make_tree_node(key, val, tree->nil, RED));
}
