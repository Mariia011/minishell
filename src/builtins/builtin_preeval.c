/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_preeval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:07:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 18:27:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtin_preeval(t_cmd * cmd)
{
	if (cmd->forkable)
	{
		cmd->pid = fork();
		if (0 == cmd->pid)
		{
			cmd->eval_core(cmd);
			exit(get_exit_status());
		}
	}
	else
		cmd->eval_core(cmd);
}
