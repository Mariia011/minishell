/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ast_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:57:29 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/25 19:24:31 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void insert_ast_node(t_ast *the_tree, t_ast_node *node)
{
    if(!the_tree->root)
    {
		the_tree->root = node;
		return ;
	}
	t_ast_node *tmp = the_tree->root;
	while(tmp && tmp->left)
		tmp = tmp->left;
	tmp->left = node;
	node->p = tmp;
}

