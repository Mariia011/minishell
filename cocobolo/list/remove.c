/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:31:20 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pop(t_list *list, t_listnode *node)
{
	if (!list || !node)
		return ;
	if (node == list->head)
		pop_front(list);
	else if (node == list->tail)
		pop_back(list);
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node->val);
		free(node);
	}
}

size_t	list_remove(t_list *list, t_list_value val)
{
	return (list_remove_if(list, val, list_value_same));
}

size_t	list_remove_if(t_list *list, t_list_value val, t_list_Bpredicate_val p)
{
	size_t	removed;
	t_listnode	*node;
	t_listnode	*next;

	if (!list || empty(list) || !val)
		return (0);
	removed = 0;
	node = list->head;
	while (node)
	{
		next = node->next;
		if (p(node->val, val) == true)
		{
			pop(list, node);
			removed++;
		}
		node = next;
	}
	return (removed);
}
