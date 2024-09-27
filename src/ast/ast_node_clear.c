/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:03:50 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/27 22:19:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ast_node_clear(t_ast_node *node)
{
	if (!node)
		return;

	__t_cmd__(node->cmd_ptr);
	__delete_string(&node->filename);
	node->fd = -1;
	free(node);
}
