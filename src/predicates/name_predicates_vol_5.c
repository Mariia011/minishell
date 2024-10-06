/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:41:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/06 14:44:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_and_token(t_listnode *node, t_shell *shell)
{
	return (is_and(node->val) && !find_addr(shell->quoted_tokens, node));
}

bool	is_or_node_token(t_listnode *node, t_shell *shell)
{
	return (is_or(node->val) && !find_addr(shell->quoted_tokens, node));
}

bool	is_or(char *val)
{
	return (string_equal(val, "||"));
}

bool	is_and(char *val)
{
	return (string_equal(val, "&&"));
}

bool	is_pipe(char *val)
{
	return (string_equal(val, "|"));
}
