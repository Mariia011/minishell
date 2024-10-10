/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:43:09 by kali              #+#    #+#             */
/*   Updated: 2024/10/07 00:49:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void recover_variables(t_list *tokens, t_shell *shell)
{
	t_listnode *t = tokens->head;

	while (t && t->next)
	{
		if (!find_addr(shell->quoted_tokens, t) && string_equal(t->val, "<<") && find_addr(shell->dollar_tokens, t->next))
		{
			__delete_string(&t->next->val);
			t->next->val = __strdup(get_orig_val(t->next, shell));
		}
		t = t->next;
	}
}
