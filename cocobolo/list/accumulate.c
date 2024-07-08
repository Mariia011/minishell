/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accumulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:37:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 16:55:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static size_t __accumulate__(t_node *head, size_t sum_so_far, t_list_Apredicate_val p)
{
	if (!head) return sum_so_far;

	p(&sum_so_far, head->val);

	return __accumulate__(head->next, sum_so_far, p);
}

size_t accumulate(t_list *list, size_t sum_so_far, t_list_Apredicate_val p)
{
	if (!list || !p) return sum_so_far;

	return __accumulate__(list->head, sum_so_far, p);
}
