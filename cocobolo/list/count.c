/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:19:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

size_t	count(t_listnode *first, t_listnode *last, t_list_value val)
{
	size_t	res;

	if (NULL == first || NULL == last)
		return (0);
	res = 0;
	while (first && first->prev != last)
	{
		if (string_equal(first->val, val) == true)
			res++;
		first = first->next;
	}
	return (res);
}

size_t	count_range(t_list *list, t_list_value val)
{
	if (NULL == list)
		return (0);
	return (count(list->head, list->tail, val));
}

size_t	count_if(t_listnode *first, t_listnode *last, t_list_Countpredicate p)
{
	size_t	res;

	if (NULL == first || NULL == last || NULL == p)
		return (0);
	res = 0;
	while (first && first->prev != last)
	{
		if (p(first->val) == true)
			res++;
		first = first->next;
	}
	return (res);
}

#pragma GCC diagnostic pop
