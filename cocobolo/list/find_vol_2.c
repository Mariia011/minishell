/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vol_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:40:57 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static t_listnode	*__find_if__(t_listnode *curr, t_listnode *last, t_list_Upredicate_b p)
{
	if (!curr || curr->prev == last)
		return (NULL);
	if (p(curr) == true)
		return (curr);
	return (__find_if__(curr->next, last, p));
}

t_listnode	*find_if(t_listnode *first, t_listnode *last, t_list_Upredicate_b p)
{
	if (!first || !last || !p)
		return (NULL);
	return (__find_if__(first, last, p));
}

#pragma GCC diagnostic pop
