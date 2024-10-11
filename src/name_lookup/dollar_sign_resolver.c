/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 11:09:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	__pshurik__(t_listnode *token, t_shell *shell);

void	dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	t_list		*queue;
	t_listnode	*token;
	t_listnode	*next;

	if (!tokens || !shell)
		return ;
	queue = make_list();
	token = tokens->head;
	while (token)
	{
		next = token->next;
		if (is_quote(token->val))
		{
			if (empty(queue))
				push_back(queue, token->val);
			else if (string_equal(queue->head->val, token->val))
				pop_front(queue);
		}
		if ((empty(queue) || string_equal(queue->head->val, "\""))
			&& __strchr(token->val, '$'))
			__pshurik__(token, shell);
		token = next;
	}
	list_clear(&queue);
}

static void	__pshurik__(t_listnode *token, t_shell *shell)
{
	save_token(shell->dollar_tokens, token);
	save_orig_value(token, shell);
	token->val = resolve(token->val, shell);
}
