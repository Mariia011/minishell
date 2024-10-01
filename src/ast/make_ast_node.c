/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:36:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node *make_op_node(t_listnode *token)
{
	t_ast_node *res = __malloc(sizeof(t_ast_node));
	res->type = node_gettype(token);
	res->cmd_ptr = NULL;
	res->fd = -1;
	res->filename = NULL;
	res->left = NULL;
	res->right = NULL;
	res->p = NULL;
	res->orig_token = token;

	return (res);
}
