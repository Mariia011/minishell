/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:21:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sort_tokens(t_cmd *cmd, t_list *tokens)
{
	t_node	*token;

	if (!cmd)
		return (-1);
	token = front(tokens)->next;
	while (token && token->val && token->val[0] == '-')
	{
		push_back(cmd->options, token->val);
		token = token->next;
	}
	while (token)
	{
		push_back(cmd->args, token->val);
		token = token->next;
	}
	return (0);
}
