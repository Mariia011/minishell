/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/27 22:30:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node *make_cmd_node(t_cmd *cmd)
{
	t_ast_node *res = __malloc(sizeof(t_ast_node));
	res->type = CMD;
	res->cmd_ptr = cmd;
	res->orig_token = NULL;
	res->fd = -1;
	res->filename = NULL;
	res->left = NULL;
	res->right = NULL;
	res->p = NULL;

	return (res);
}