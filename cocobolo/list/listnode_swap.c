/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnode_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:53:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:21:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	listnode_swap(t_listnode *lhv, t_listnode *rhv)
{
	char	*t;

	if (!lhv || !rhv)
		return ;
	t = lhv->val;
	lhv->val = rhv->val;
	rhv->val = t;
}
