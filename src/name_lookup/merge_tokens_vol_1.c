/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens_vol_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:38:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool		is_self_mergeable(t_listnode *token);
bool		is_mergeable(t_listnode *token, t_set *quoted_tokens);
bool		__small_condition__(t_listnode *token, t_shell *shell);
bool		__scary_condition__(t_listnode *token, t_listnode *next,
				t_shell *shell);

static void	merge_inside_quotes(t_list *tokens);
static void	merge_inside_quotes_the_good_part(t_list *tokens, t_listnode **t,
				t_listnode **next);

void	merge_tokens(t_shell *shell, t_list *tokens)
{
	t_listnode	*token;
	t_listnode	*next;

	if (!tokens || empty(tokens))
		return ;
	merge_inside_quotes(tokens);
	mark_quoted_tokens(shell, tokens);
	token = front(tokens);
	while (token && token->next)
	{
		next = token->next;
		if (__small_condition__(token, shell))
		{
			token = next;
			continue ;
		}
		if (__scary_condition__(token, next, shell))
		{
			token->val = __strappend(token->val, next->val, NULL);
			pop(tokens, next);
			next = token;
		}
		token = next;
	}
}

static void	merge_inside_quotes(t_list *tokens)
{
	t_listnode	*token;
	t_listnode	*next;

	if (!tokens || empty(tokens))
		return ;
	token = front(tokens);
	while (token)
	{
		next = token->next;
		if (is_quote(token->val))
		{
			merge_inside_quotes_the_good_part(tokens, &token, &next);
		}
		token = next;
	}
}

static void	merge_inside_quotes_the_good_part(t_list *tokens, t_listnode **t,
		t_listnode **next)
{
	t_listnode	*tmp;
	char		*quote_type;

	quote_type = __strdup((*t)->val);
	if ((*t)->next && string_equal((*t)->next->val, quote_type))
	{
		list_insert(tokens, (*t), "");
		(*next) = (*t)->next;
	}
	(*t) = (*t)->next;
	tmp = (*t)->next;
	while (tmp && string_equal(tmp->val, quote_type) == false)
	{
		(*next) = tmp->next;
		(*t)->val = __strappend((*t)->val, tmp->val, NULL);
		pop(tokens, tmp);
		tmp = (*next);
	}
	if (tmp)
		tmp = tmp->next;
	(*next) = tmp;
	__delete_string(&quote_type);
}
