/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_vol_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:23:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_list	*make_list(void)
{
	t_list	*list;

	list = __malloc(sizeof(t_list));
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_list	*make_list_copy_range(t_list *other, t_value_mutate f)
{
	if (!other)
		return (NULL);
	return (make_list_copy(other->head, other->tail, f));
}

t_list	*make_list_copy(t_node *first, t_node *last, t_value_mutate f)
{
	t_list			*list;
	t_list_value	val;

	list = make_list();
	while (first && first->prev != last)
	{
		if (f == NULL)
		{
			push_back(list, first->val);
		}
		else
		{
			val = f(first->val);
			push_back(list, val);
			free(val);
		}
		first = first->next;
	}
	return (list);
}

void	list_move_back(t_list *lhv, t_list *rhv)
{
	if (!lhv || !rhv || empty(lhv) || lhv == rhv)
		return ;
	if (empty(rhv))
	{
		*rhv = *lhv;
	}
	else
	{
		lhv->head->prev = rhv->tail;
		rhv->tail->next = lhv->head;
		rhv->tail = lhv->tail;
	}
	lhv->head = NULL;
	lhv->tail = NULL;
}

#pragma GCC diagnostic pop
