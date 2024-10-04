/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_7.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:42:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:42:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	not_space(t_listnode *node)
{
	return (node && !string_equal(node->val, " "));
}

bool	is_special_symbol(t_listnode *node, t_shell *shell)
{
	return (is_and_token(node, shell) || is_or_node_token(node, shell)
		|| is_pipe_token(node, shell) || is_redirection_token(node, shell));
}

bool	is_binary_operator(t_listnode *node, t_shell *shell)
{
	return (is_special_symbol(node, shell) && !is_redirection_token(node,
			shell));
}

bool	not_binary_operator_nor_parenthesis(t_listnode *node, t_shell *shell)
{
	return (!is_binary_operator(node, shell) && !is_parenthesis_token(node,
			shell));
}

bool	not_binary_operator(t_listnode *node, t_shell *shell)
{
	return (!is_binary_operator(node, shell));
}
