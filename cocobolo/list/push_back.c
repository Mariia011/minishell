/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:58:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	push_back(t_list *const list, const t_list_value x)
{
	t_listnode	*node;

	if (!list)
		return ;
	node = make_node(x);
	node->prev = list->tail;
	if (NULL == list->head)
		list->head = node;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
}

// void push_back(t_list *const list, const t_list_value x, ...)
// {
// 	if (NULL == list) __exit("nullptr passed to push_back");

// 	va_list args;
// 	va_start(args, x);

// 	__va__push_back__(list, x, args, NULL);

// 	va_end(args);
// }

#pragma GCC diagnostic pop
