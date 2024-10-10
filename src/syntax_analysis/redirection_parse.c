/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:23:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 19:46:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirection_parse(t_list *tokens, t_shell *shell)
{
	t_listnode	*rdr;

	rdr = shfind_if(tokens->head, tokens->tail, is_redirection_token, shell);
	while (rdr)
	{
		rdr = rdr->next;
		while (rdr && string_equal(rdr->val, " "))
			rdr = rdr->next;
		if (!rdr)
		{
			__perror("parse error near token `newline\'");
			return (false);
		}
		else if (is_special_symbol(rdr, shell) || is_parenthesis_token(rdr,
				shell))
		{
			__va_perror("parse error near token ", rdr->val, NULL);
			return (false);
		}
		rdr = shfind_if(rdr->next, tokens->tail, is_redirection_token, shell);
	}
	return (true);
}
