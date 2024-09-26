/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:00:06 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 03:07:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// size_t lsttrim(t_list *list, char *set)
// {
// 	if (!list || !set)
// 		return (0);

// 	size_t res = 0;

// 	t_node *curr = list->head;

// 	bool f = true;

// 	while (curr && f)
// 	{
// 		t_node *n = curr->next;
// 		f = false;
// 		size_t i = 0;
// 		while (set[i])
// 		{
// 			char *t_val = __make_string_from_char(set[i]);
// 			if (string_equal(curr->val, t_val))
// 			{
// 				pop(list, curr);
// 				res++;
// 				f = true;
// 			}
// 			__delete_string(&t_val);
// 			i++;
// 		}
// 		curr = n;
// 	}

// 	curr = list->tail;


// 	return res;
// }
