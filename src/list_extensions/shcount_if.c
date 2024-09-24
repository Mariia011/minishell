/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shcount_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:33:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 15:55:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	shcount_if(t_node *first, t_node *last, bool (*p)(t_node *, t_shell *), t_shell *shell)
{
	size_t	res;

	if (NULL == first || NULL == last || NULL == p)
		return (0);
	res = 0;
	while (first && first->prev != last)
	{
		if (p(first, shell) == true)
			res++;
		first = first->next;
	}
	return (res);
}
