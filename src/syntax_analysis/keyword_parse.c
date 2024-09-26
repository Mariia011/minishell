/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:22:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 02:42:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	keyword_parse(t_list *tokens, t_shell *shell)
{
	t_node	*token;
	t_node	*pair;

	if (!tokens)
		return (true);
	token = NULL;
	token = shfind_if(tokens->head, tokens->tail, is_special_symbol, shell);
	if (token == tokens->head)
	{
		__va_perror("parse error near token `", token->val, "\'", NULL);
		return (false);
	}
	while (token)
	{
		pair = shfind_if(token->next, tokens->tail, is_special_symbol, shell);
		if (!pair)
			pair = back(tokens);
		else
			pair = pair->prev;
		if (NULL == shfind_if(token->next, pair, not_special_symbol, shell))
		{
			__va_perror("parse error near token `", token->val, "\'", NULL);
			return (false);
		}
		token = shfind_if(pair->next, tokens->tail, is_pipe_token, shell);
	}
	return (true);
}

