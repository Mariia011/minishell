/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:41:51 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 18:26:54 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_alpha(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_name_part(const char c)
{
	return (c == '_' || is_alpha(c) || is_digit(c));
}

bool	is_single_redirection(char *val)
{
	return (string_equal(val, "<") || string_equal(val, ">"));
}