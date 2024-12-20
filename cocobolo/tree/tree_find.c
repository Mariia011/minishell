/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:28:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static t_tree_node	*__tree_find__(t_tree *tree, t_tree_node *x, t_treeval key)
{
	if (x == tree->nil)
		return (tree->nil);
	if (tree->less(x->key, key))
		return (__tree_find__(tree, x->right, key));
	else if (tree->less(key, x->key))
		return (__tree_find__(tree, x->left, key));
	else
		return (x);
}

t_tree_node	*tree_find(t_tree *tree, t_treeval key)
{
	return (__tree_find__(tree, tree->root, key));
}

// t_tree_node *__tree_find_if__(t_tree_node *root, t_treeval key, t_cmp p)
// {
// 	if (!root) return (NULL);

// 	if (p(root->val, key) == true) return (root);

// 	t_tree_node * guess = __tree_find_if__(root->left, key, p);

// 	if (guess) return (guess);

// 	else
// 		return (__tree_find_if__(root->right, key, p));
// }

// t_tree_node *tree_find_if(t_tree *tree, t_treeval key, t_cmp p)
// {
// 	if (tree_empty(tree) || !key || !p) return (NULL);

// 	return (__tree_find_if__(tree->root, key, p));
// }
