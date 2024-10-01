/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:53:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:55:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void listnode_swap(t_listnode *lhv, t_listnode *rhv)
{
	if (!lhv || !rhv)
		return;

	char *t = lhv->val;
	lhv->val = rhv->val;
	rhv->val = t;
}
