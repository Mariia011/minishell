/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:08:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 16:26:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*tokenize(char *raw_cmd)
{
	t_list	*tokens;

	if (!raw_cmd)
		return (NULL);
	tokens = make_list_from_string(raw_cmd, SPECIAL_SYMBOLS, all);
	if (!tokens || quote_parse(tokens) == -1)
	{
		set_exit_status(2);
		list_clear(&tokens);
	}
	return (tokens);
}
