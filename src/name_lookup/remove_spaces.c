/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:42:49 by kali              #+#    #+#             */
/*   Updated: 2024/10/11 10:43:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_spaces(t_shell *shell, t_list *tokens)
{
	t_listnode	*curr;
	t_listnode	*next;

	if (!shell || empty(tokens))
		return ;
	curr = shfind_if(tokens->head, tokens->tail, is_space_token, shell);
	while (curr)
	{
		next = curr->next;
		pop(tokens, curr);
		curr = shfind_if(next, tokens->tail, is_space_token, shell);
	}
}
