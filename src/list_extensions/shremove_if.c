/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shremove_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:09:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	shremove_if(t_list *list, bool (*p)(t_listnode *, t_shell *), t_shell *shell)
{
	size_t	removed;
	t_listnode	*next;
	t_listnode	*first;

	if (!list || !p || !shell)
		return (0);
	removed = 0;
	first = list->head;
	while (first)
	{
		next = first->next;
		if (p(first, shell) == true)
		{
			pop(list, first);
			removed++;
		}
		first = next;
	}
	return (removed);
}

