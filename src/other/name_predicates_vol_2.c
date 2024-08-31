/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:26:29 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/31 21:01:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection(char *val)
{
	return (string_equal(val, "<") || string_equal(val, ">")
		|| string_equal(val, "<<") || string_equal(val, ">>"));
}
bool	is_quote(char *s)
{
	return (string_equal(s, "\'") || string_equal(s, "\""));
}

bool	is_name(char *s)
{
	if (!s || (*s != '_' && !is_alpha(*s)))
		return (false);
	++s;
	while (*s)
	{
		if (!is_name_part(*s))
			return (false);
		++s;
	}
	return (true);
}

bool	not_name_part(char c)
{
	return (!is_name_part(c));
}
