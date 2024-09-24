/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_gettype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:41:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 00:47:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node_type node_gettype(t_node *token)
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
