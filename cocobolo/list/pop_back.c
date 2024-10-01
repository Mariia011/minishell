/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:40:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	pop_back(t_list *const list)
{
	t_listnode	*to_remove;

	if (NULL == list || NULL == list->tail)
		return ;
	if (list->head == list->tail)
		list->head = NULL;
	to_remove = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	free(to_remove->val);
	free(to_remove);
}

#pragma GCC diagnostic pop
