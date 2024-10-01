/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:05:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 16:09:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void list_extract(t_list *list, t_listnode *node)
{
	if (!list || !node)
		return;

	if (node == list->head)
		list->head = node->next;
	else
		node->prev->next = node->next;

	if (node == list->tail)
		list->tail = node->prev;
	else
		node->next->prev = node->prev;
}
