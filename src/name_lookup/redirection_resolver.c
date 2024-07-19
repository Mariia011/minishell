/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:32:15 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/20 00:52:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int redirection_resolver(t_list *tokens)
{
    t_node *token = tokens->head;
    
	while (token)
	{
		t_node *next = token->next;
        
		if (list_value_same(token->val, "<") || list_value_same(token->val, ">") || list_value_same(token->val, ">>")) 
		{
			int redir = redirect(token);

			if (-1 == redir) return -1;

			t_node *next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
			token = next;
			continue;
		}
		token = next;
	}
    return 0;
}