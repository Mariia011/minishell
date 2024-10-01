/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:22:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 17:01:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	keyword_parse(t_list *tokens, t_shell *shell)
{
	t_listnode	*token;
	t_listnode	*pair;

	if (!tokens)
		return (true);
	token = NULL;
	token = shfind_if(tokens->head, tokens->tail, is_binary_operator, shell);
	if (token == tokens->head)
	{
		__va_perror("parse error near token `", token->val, "\'", NULL);
		return (false);
	}
	while (token)
	{
		pair = shfind_if(token->next, tokens->tail, is_binary_operator, shell);
		if (!pair)
			pair = back(tokens);
		else
			pair = pair->prev;
		if (NULL == shfind_if(token->next, pair, not_binary_operator, shell))
		{
			__va_perror("parse error near token `", token->val, "\'", NULL);
			return (false);
		}
		token = shfind_if(pair->next, tokens->tail, is_pipe_token, shell);
	}
	return (true);
}

