/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:36:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 22:35:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pop_front(t_list *const list)
{
	t_node	*to_remove;

	if (NULL == list || NULL == list->head)
		return ;

	to_remove = list->head;

	list->head = list->head->next;

	if (list->head)
		list->head->prev = NULL;

	free(to_remove->val);
	free(to_remove);
}

