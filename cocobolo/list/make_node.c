/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:01:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_listnode	*make_node(const t_list_value x)
{
	t_listnode	*node;

	node = __malloc(sizeof(t_listnode));
	node->val = __strdup(x);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

#pragma GCC diagnostic pop
