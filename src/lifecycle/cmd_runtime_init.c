/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_runtime_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:39:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/27 22:45:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cmd_runtime_init(t_cmd *cmd)
{
	wildcard_resolve(cmd->tokens, cmd->shell);

	// add redirection handling
	if (empty(cmd->tokens) || sort_tokens(cmd, cmd->tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		cmd->invokable = false;
	}
}
