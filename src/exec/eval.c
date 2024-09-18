/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/16 19:46:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eval(t_cmd_container *cmds)
{
	t_command	*cmd;

	if (NULL == cmds)
		return ;
	while (cmds->current_cmd_index < cmds->size)
	{
		cmd = cmds->arr[cmds->current_cmd_index];
		if (cmd)
		{
			cmd->eval(cmd);
			if (cmd->redirection & redirect_heredoc)
				unlink(HEREDOC);
			if (cmd->pid == -1)
				return ;
		}
		cmds->current_cmd_index++;
	}
	while (-1 != wait(NULL))
		;
}
