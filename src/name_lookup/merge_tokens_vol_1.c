/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens_vol_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 10:46:22 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool		is_self_mergeable(t_listnode *token);
bool		is_mergeable(t_listnode *token, t_set *quoted_tokens);
bool		__small_condition__(t_listnode *token, t_shell *shell);
bool		__scary_condition__(t_listnode *token, t_listnode *next,
				t_shell *shell);

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
