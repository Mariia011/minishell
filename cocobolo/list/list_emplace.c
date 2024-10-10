/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_emplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:21:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_listnode	*list_emplace(t_list *list, t_listnode *pos, t_listnode *node)
{
	bool	b;

	if (empty(list) || node == NULL)
		return (NULL);
	b = false;
	if (pos == NULL)
	{
		b = true;
		push_back(list, "dummy");
		pos = list->tail;
	}
	node->next = pos;
	if (pos->prev)
		pos->prev->next = node;
	else
		list->head = node;
	node->prev = pos->prev;
	pos->prev = node;
	if (b)
		pop_back(list);
	return (node);
}
