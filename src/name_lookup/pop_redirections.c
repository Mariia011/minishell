/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:37:08 by codespace         #+#    #+#             */
/*   Updated: 2024/10/06 04:39:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pop_redirections(t_list *partition, t_shell *shell)
{
	t_listnode	*token;
	t_listnode	*next;

	token = partition->head;
	while (token && token->next)
	{
		next = token->next;
		if (is_redirection_token(token, shell))
		{
			next = token->next->next;
			erase(partition, token, token->next);
		}
		token = next;
	}
	return (0);
}
