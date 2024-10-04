/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:41:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:51:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_and_token(t_listnode *node, t_shell *shell)
{
	return (is_and(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}

bool	is_or_node_token(t_listnode *node, t_shell *shell)
{
	return (is_or(node->val) && !is_quoted_token(shell->quoted_tokens, node));
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
