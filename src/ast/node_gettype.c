/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_gettype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:41:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:10:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node_type	node_gettype(t_listnode *token)
{
	if (is_or(token->val))
		return (OR);
	else if (is_and(token->val))
		return (AND);
	else if (is_pipe(token->val))
		return (PIPE);
	else if (is_redirection(token->val))
		return (REDIRECTION);
	else
		return (CMD);
}
