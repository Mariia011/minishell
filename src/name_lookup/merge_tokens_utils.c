/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/06 14:42:17 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_token(t_set *set, t_listnode *address)
{
	char	*val;

	val = __ptoa((size_t)address);
	set_insert(set, val);
	free(val);
}

bool	is_quote_node(t_listnode *const node)
{
	return (is_quote(node->val));
}

void	mark_quoted_tokens(t_shell *shell, t_list *tokens)
{
	t_listnode	*left_quote;
	t_listnode	*right_quote;
	t_listnode	*token;

	if (empty(tokens))
		return ;
	left_quote = find_if(front(tokens), back(tokens), is_quote_node);
	if (!left_quote)
		return ;
	while (left_quote)
	{
		right_quote = find(left_quote->next, back(tokens), left_quote->val,
				string_equal);
		token = left_quote->next;
		while (token && token != right_quote)
		{
			save_token(shell->quoted_tokens, token);
			token = token->next;
		}
		pop(tokens, left_quote);
		left_quote = find_if(right_quote->next, back(tokens), is_quote_node);
		pop(tokens, right_quote);
	}
}

void	erase_quotes(t_list *tokens)
{
	t_listnode	*token;
	t_listnode	*pair;

	if (empty(tokens))
		return ;
	token = find_if(front(tokens), back(tokens), is_quote_node);
	while (token)
	{
		pair = find(token->next, back(tokens), token->val, string_equal);
		if (!pair)
			break ;
		pop(tokens, token);
		token = find_if(pair->next, back(tokens), is_quote_node);
		pop(tokens, pair);
	}
}
