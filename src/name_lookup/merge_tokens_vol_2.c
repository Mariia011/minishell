/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens_vol_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:36:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:37:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_self_mergeable(t_listnode *token)
{
	return (token && token->val && __strlen(token->val) == 1
		&& __strchr(SELF_MERGEABLE_TOKENS, token->val[0]));
}

bool	is_mergeable(t_listnode *token, t_set *quoted_tokens)
{
	return (is_quoted_token(quoted_tokens, token) || (!is_self_mergeable(token)
			&& (!is_parenthesis(token->val) && !string_equal(token->val,
					" "))));
}

bool	__small_condition__(t_listnode *token, t_shell *shell)
{
	return (string_equal(token->val, "<<") || string_equal(token->val, ">>")
		|| is_opening_parenthesis_token(token, shell)
		|| is_closing_parenthesis_token(token, shell));
}

bool	__scary_condition__(t_listnode *token, t_listnode *next, t_shell *shell)
{
	return ((is_quoted_token(shell->quoted_tokens, token)
			&& is_quoted_token(shell->quoted_tokens, token->next))
		|| (is_self_mergeable(token) && string_equal(next->val, token->val)
			&& !is_quoted_token(shell->quoted_tokens, next))
		|| (is_mergeable(token, shell->quoted_tokens) && (is_mergeable(next,
					shell->quoted_tokens)
				|| is_quoted_token(shell->quoted_tokens, next))));
}
