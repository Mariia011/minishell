/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttopsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:28:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 17:49:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void remove_aux_redirections(t_list *tokens, t_shell *shell);

void ttopsort(t_list *tokens, t_shell *shell)
{
	if (!tokens || !shell)
		return;
	remove_aux_redirections(tokens, shell);
}

static void remove_aux_redirections(t_list *tokens, t_shell *shell)
{
	t_listnode *lb = tokens->head;

	while (lb)
	{
		t_listnode * ub = shfind_if(lb->next, tokens->tail, is_binary_operator, shell);

		if (!ub)
			ub = tokens->tail;

		t_listnode *r = shrfind_if(lb, ub, is_redirection_token, shell);

		if (r)
		{
			t_listnode *t = lb;
			while (t != r)
			{
				t_listnode *n = t->next;
				if (is_redirection_token(t, shell))
				{
					n = t->next->next;
					pop(tokens, t->next);
					pop(tokens, t);
				}
				t = n;
			}
		}

		lb = shfind_if(ub->next, tokens->tail, is_binary_operator, shell);
	}
}

