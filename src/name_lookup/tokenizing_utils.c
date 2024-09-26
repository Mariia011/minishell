/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:29:11 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/26 02:42:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


bool	not_space(t_node *node)
{
	return (node && !string_equal(node->val, " "));
}

bool is_special_symbol(t_node * node, t_shell *shell)
{
	return (is_and_token(node, shell) || is_or_node_token(node, shell) || is_pipe_token(node, shell) || is_redirection_token(node, shell));
}

bool not_special_symbol(t_node * node, t_shell *shell)
{
	return (!is_special_symbol(node, shell));
}

bool	is_redirection_token(t_node *node, t_shell *shell)
{
	return (is_redirection(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}

bool is_wildcard(t_node *node) // quoted???
{
	// return(__strchr(node->val, '*'));
	return(__strchr(node->val, '*'));
}

bool is_not_wildcard(t_node *node)
{
	// return(__strchr(node->val, '*'));
	return(!string_equal(node->val, "*"));
}

bool is_pipe_token(t_node *node, t_shell *shell)
{
	return (is_pipe(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}

bool is_and_token(t_node *node, t_shell *shell)
{
	return (is_and(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}

bool is_or_node_token(t_node *node, t_shell *shell)
{
	return (is_or(node->val) && !is_quoted_token(shell->quoted_tokens, node));
}

bool is_or(char *val)
{
	return (string_equal(val, "||"));
}

bool is_and(char *val)
{
	return (string_equal(val, "&&"));
}

bool is_pipe(char *val)
{
	return (string_equal(val, "|"));
}
