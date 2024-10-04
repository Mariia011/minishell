/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_vol_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:22:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:23:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_list_no_nl(t_list *list)
{
	if (NULL == list)
		return ;
	preorder_traverse(list->head, __print_listnode_no_nl__);
}

void	print_list_custom(t_list *list, t_list_upredicate p)
{
	if (NULL == list || NULL == p)
		return ;
	preorder_traverse(list->head, p);
}

void	print_list_enumerate(t_list *list)
{
	if (NULL == list)
		return ;
	__print_listnode_enumerate__(list->head, 1);
}
