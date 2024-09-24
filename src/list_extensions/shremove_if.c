/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shremove_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:09:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 16:14:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	shremove_if(t_list *list, bool (*p)(t_node *, t_shell *), t_shell *shell)
{
	size_t	removed;
	t_node	*next;
	t_node	*first;

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

