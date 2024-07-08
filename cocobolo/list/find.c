/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:18:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 22:27:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_node *__find(t_node *head, t_list_value target, t_list_Bpredicate_val cmp)
{
    if (!head) return NULL;

    if (cmp(head->val, target) == true) return head;

    return __find(head->next, target, cmp);
}

t_node *find(t_list *list, t_list_value target, t_list_Bpredicate_val cmp)
{
    if (!list) return NULL;

    return __find(list->head, target, cmp);
}

t_node *find_strict(t_list *list, t_list_value target, t_list_Bpredicate_val cmp)
{
    t_node *res = find(list, target, cmp);

	if (NULL == res) __exit("bad strict find");

	return res;
}