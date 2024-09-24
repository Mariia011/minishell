/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shfind_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:33:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 16:45:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*__shfind_if__(t_node *curr, t_node *last, bool (*p)(t_node *, t_shell*), t_shell *shell)
{
	if (!curr || curr->prev == last)
		return (NULL);
	if (p(curr, shell) == true)
		return (curr);
	return (__shfind_if__(curr->next, last, p, shell));
}

t_node	*shfind_if(t_node *first, t_node *last, bool (*p)(t_node *, t_shell*), t_shell *shell)
{
	if (!first || !last || !p)
		return (NULL);
	return (__shfind_if__(first, last, p, shell));
}

static t_node	*__shrfind_if__(t_node *curr, t_node *last, bool (*p)(t_node *, t_shell*), t_shell *shell)
{
	if (!curr || curr->next == last)
		return (NULL);
	if (p(curr, shell) == true)
		return (curr);
	return (__shrfind_if__(curr->prev, last, p, shell));
}

t_node	*shrfind_if(t_node *first, t_node *last, bool (*p)(t_node *, t_shell*), t_shell *shell)
{
	if (!first || !last || !p)
		return (NULL);
	return (__shrfind_if__(last, first, p, shell));
}
