/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:28:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 19:22:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree_node *__tree_find__(tree_node *root, t_treeval key)
{
 	if (NULL == root)
		return NULL;
	if (less(root->key, key))
		return(__tree_find__(root->right, key));
	else if (less(key, root->key))
		return(__tree_find__(root->left, key));
	else
		return root;
}

tree_node *tree_find(t_tree *tree, t_treeval key)
{
	return(__tree_find__(tree->root, key));
}

tree_node *__tree_find_if__(tree_node *root, t_treeval key, tree_binary_predicate p)
{
	if (!root) return NULL;

	if (p(root->val, key) == true) return root;

	tree_node * guess = __tree_find_if__(root->left, key, p);

	if (guess) return guess;

	else
		return __tree_find_if__(root->right, key, p);
}

tree_node *tree_find_if(t_tree *tree, t_treeval key, tree_binary_predicate p)
{
	if (tree_empty(tree) || !key || !p) return NULL;

	return __tree_find_if__(tree->root, key, p);
}