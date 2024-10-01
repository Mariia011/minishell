/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:30:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	merge_redirections(t_list *tokens)
{
	t_listnode	*token;
	t_listnode	*next;

	if (!tokens)
		return ;
	token = front(tokens);
	while (token && token->next)
	{
		next = token->next;
		if (is_single_redirection(token->val) && string_equal(token->val,
				token->next->val))
		{
			token->val = __strappend(token->val, token->next->val, NULL);
			next = token->next->next;
			pop(tokens, token->next);
		}
		token = next;
	}
}
