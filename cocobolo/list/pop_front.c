/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:36:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	pop_front(t_list *const list)
{
	t_listnode	*to_remove;

	if (NULL == list || NULL == list->head)
		return ;
	if (list->head == list->tail)
		list->tail = NULL;
	to_remove = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	free(to_remove->val);
	free(to_remove);
}

#pragma GCC diagnostic pop
