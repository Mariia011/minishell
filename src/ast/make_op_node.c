/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_op_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:18:36 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/25 19:24:38 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node *make_op_node(t_ast_node_type type)
{
	t_ast_node *node = __malloc(sizeof(t_ast_node));
	node->type = type;
	node->cmd_ptr = NULL;
	node->fd = -1;
	node->right = NULL;
	node->left = NULL;
	node->p = NULL;
	return node;
}
