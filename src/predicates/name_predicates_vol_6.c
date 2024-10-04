/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:41:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:50:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	not_special_symbol(t_listnode *node, t_shell *shell)
{
	return (!is_special_symbol(node, shell));
}

bool	is_redirection_token(t_listnode *node, t_shell *shell)
{
	return (is_redirection(node->val) && !is_quoted_token(shell->quoted_tokens,
			node));
}

bool	is_wildcard(t_listnode *node)
{
	return (__strchr(node->val, '*'));
}

bool	is_not_wildcard(t_listnode *node)
{
	return (!string_equal(node->val, "*"));
}

bool	is_pipe_token(t_listnode *node, t_shell *shell)
{
	return (is_pipe(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}
