/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:23:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 16:28:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirection_parse(t_list *tokens, t_shell *shell)
{
	t_node	*rdr;

	if (!tokens)
		return (true);
	rdr = NULL;
	rdr = find_if(front(tokens), back(tokens), is_redir);
	while (rdr && is_quoted_token(shell->quoted_tokens, rdr))
		rdr = find_if(rdr->next, back(tokens), is_redir);
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
		else if (is_redirection(rdr->val) && !is_quoted_token(shell->quoted_tokens, rdr))
		{
			__va_perror("parse error near token ", rdr->val, NULL);
			return (false);
		}
		rdr = find_if(rdr->next, back(tokens), is_redir);
	}
	return (true);
}
