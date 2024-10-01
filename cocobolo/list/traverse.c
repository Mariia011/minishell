/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:50:20 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	preorder_traverse(t_listnode *head, t_list_Upredicate f)
{
	if (NULL == head)
		return ;
	f(head);
	preorder_traverse(head->next, f);
}

void	reverse_preorder_traverse(t_listnode *head, t_list_Upredicate f)
{
	if (NULL == head)
		return ;
	f(head);
	reverse_preorder_traverse(head->prev, f);
}

void	postorder_traverse(t_listnode *head, t_list_Upredicate f)
{
	if (NULL == head)
		return ;
	postorder_traverse(head->next, f);
	f(head);
}

void	reverse_postorder_traverse(t_listnode *head, t_list_Upredicate f)
{
	if (NULL == head)
		return ;
	reverse_postorder_traverse(head->prev, f);
	f(head);
}

#pragma GCC diagnostic pop
