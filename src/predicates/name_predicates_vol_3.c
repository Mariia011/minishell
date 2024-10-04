/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:47:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:50:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_opening_parenthesis_token(t_listnode *token, t_shell *shell)
{
	return (!is_quoted_token(shell->quoted_tokens, token)
		&& is_opening_parenthesis(token->val));
}

bool	is_closing_parenthesis_token(t_listnode *token, t_shell *shell)
{
	return (!is_quoted_token(shell->quoted_tokens, token)
		&& is_closing_parenthesis(token->val));
}

bool	is_parenthesis(char *text)
{
	return (is_opening_parenthesis(text) || is_closing_parenthesis(text));
}

bool	is_opening_parenthesis(char *text)
{
	return (string_equal(text, "("));
}

bool	is_closing_parenthesis(char *text)
{
	return (string_equal(text, ")"));
}
