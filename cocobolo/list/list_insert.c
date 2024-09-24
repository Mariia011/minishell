/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:22:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_node	*list_insert(t_list *list, t_node *pos, char *val)
{
	t_node	*new;

	if (list == NULL || pos == NULL || !val)
		return (NULL);
	if (empty(list) || pos == list->tail)
	{
		push_back(list, val);
		return (list->tail);
	}
	new = make_node(val);
	new->prev = pos;
	pos->next->prev = new;
	new->next = pos->next;
	pos->next = new;
	return (new);
}

#pragma GCC diagnostic pop
