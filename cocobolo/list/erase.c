/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:49:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:20:34 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	erase(t_list *list, t_listnode *first, t_listnode *last)
{
	size_t		res;
	t_listnode	*next;

	if (empty(list) || !first || !last)
		return (0);
	res = 0;
	while (first && first != last)
	{
		next = first->next;
		pop(list, first);
		first = next;
		res++;
	}
	pop(list, last);
	return (res);
}
