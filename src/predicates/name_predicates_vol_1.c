/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:41:51 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 21:10:48 by aamirkha         ###   ########.fr       */
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

bool	is_wildcard_token(t_listnode *node, t_shell *shell)
{
	return (is_wildcard(node) && !find_addr(shell->quoted_tokens, node));
}
