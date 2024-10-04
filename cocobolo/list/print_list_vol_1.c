/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_vol_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:49:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:25:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	__print_listnode__(t_listnode *const head)
{
	if (NULL == head)
	{
		printf("\n");
		return ;
	}
	printf("%s\n", head->val);
}

void	print_list(t_list *list)
{
	if (NULL == list)
		return ;
	preorder_traverse(list->head, __print_listnode__);
}
