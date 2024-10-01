/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:49:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 17:54:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	__print_listnode__(t_listnode *const head)
{
	if (NULL == head)
	{
		printf("\n");
		return ;
	}
	printf("%s\n", head->val);
}

static void	__print_listnode_no_nl__(t_listnode *const head)
{
	printf("%s ", head->val);
	if (NULL == head->next)
		printf("\n");
}

static void	__print_listnode_enumerate__(t_listnode *const head, size_t n)
{
	if (NULL == head)
		return ;
	printf("%ld  %s\n", n, head->val);
	__print_listnode_enumerate__(head->next, n + 1);
}

void	print_list(t_list *list)
{
	if (NULL == list)
		return ;
	preorder_traverse(list->head, __print_listnode__);
}

void	print_list_no_nl(t_list *list)
{
	if (NULL == list)
		return ;
	preorder_traverse(list->head, __print_listnode_no_nl__);
}

void	print_list_custom(t_list *list, t_list_Upredicate p)
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

#pragma GCC diagnostic pop
