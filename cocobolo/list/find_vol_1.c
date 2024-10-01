/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vol_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:18:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static t_listnode	*__find(t_listnode *first, t_listnode *last, t_list_value target,
		t_list_Bpredicate_val cmp)
{
	if (!first || first->prev == last)
		return (NULL);
	if (cmp(first->val, target) == true)
		return (first);
	return (__find(first->next, last, target, cmp));
}

// find an element in range [first, last]
t_listnode	*find(t_listnode *first, t_listnode *last, t_list_value target,
		t_list_Bpredicate_val cmp)
{
	if (!first || !last)
		return (NULL);
	if (!cmp)
		cmp = list_value_same;
	return (__find(first, last, target, cmp));
}

// find an element in list { same as find(head, tail, t, cmp) }
t_listnode	*find_range(t_list *list, t_list_value target,
		t_list_Bpredicate_val cmp)
{
	if (!list)
		return (NULL);
	return (find(list->head, list->tail, target, cmp));
}

t_listnode	*find_strict(t_listnode *first, t_listnode *last, t_list_value target,
		t_list_Bpredicate_val cmp)
{
	t_listnode			*res;
	char			*err;

	res = find(first, last, target, cmp);
	err = __make_string("bad strict find ", "(", target, ")", NULL);
	if (NULL == res)
		__exit(err);
	__delete_string(&err);
	return (res);
}

#pragma GCC diagnostic pop
