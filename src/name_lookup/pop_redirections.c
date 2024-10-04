/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:37:08 by codespace         #+#    #+#             */
/*   Updated: 2024/10/04 20:38:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pop_redirections(t_list *partition, t_shell *shell)
{
	t_listnode	*token;
	t_listnode	*next;

	token = partition->head;
	while (token)
	{
		next = token->next;
		if (is_redirection_token(token, shell))
		{
			erase(partition, token, token->next);
		}
		token = next;
	}
	return (0);
}
