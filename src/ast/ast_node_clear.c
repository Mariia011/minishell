/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:03:50 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:56:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_node_clear(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->fd != -1)
		close(node->fd);
	__t_cmd__(node->cmd_ptr);
	__delete_string(&node->filename);
	node->fd = -1;
	free(node);
}
