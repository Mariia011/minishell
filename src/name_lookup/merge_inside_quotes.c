/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_inside_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:57 by kali              #+#    #+#             */
/*   Updated: 2024/10/11 10:46:24 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	merge_inside_quotes(t_list *tokens)
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

void	merge_inside_quotes_the_good_part(t_list *tokens, t_listnode **t,
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
