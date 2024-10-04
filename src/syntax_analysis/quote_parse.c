/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:27:37 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 19:46:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_parse(t_list *tokens)
{
	bool		d;
	bool		s;
	t_listnode	*token;

	d = false;
	s = false;
	token = tokens->head;
	while (token)
	{
		if (!d && string_equal(token->val, "\'"))
			s = !s;
		if (!s && string_equal(token->val, "\""))
			d = !d;
		token = token->next;
	}
	if (d || s)
	{
		if (d)
			__perror("parse error near token \"");
		else
			__perror("parse error near token \'");
		return (-1);
	}
	return (0);
}
