/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:23:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 19:39:40 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirection_parse(t_list *tokens, t_shell *shell)
{
	t_node	*rdr;

	if (!tokens)
		return (true);
	rdr = NULL;
	rdr = shfind_if(tokens->head, tokens->tail, is_redirection_node, shell);
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
		else if (is_redirection_node(rdr, shell))
		{
			__va_perror("parse error near token ", rdr->val, NULL);
			return (false);
		}
		rdr = shfind_if(rdr->next, tokens->tail, is_redirection_node, shell);
	}
	return (true);
}
