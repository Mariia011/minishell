/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:23:05 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 19:46:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parenthesis_parse(t_list *tokens, t_shell *shell)
{
	int			count;
	t_listnode	*token;

	count = 0;
	token = tokens->head;
	while (token)
	{
		if (is_opening_parenthesis_token(token, shell))
			count++;
		else if (is_closing_parenthesis_token(token, shell))
			count--;
		if (count <= -1)
			return (false);
		token = token->next;
	}
	return (count == 0);
}
