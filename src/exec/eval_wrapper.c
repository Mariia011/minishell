/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 19:30:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

void eval_wrapper(t_command *cmd, t_eval_opcode opcode)
{

	t_fd		pipe[PIPE_MAX];

	__pipe(pipe);

	if (cmd->container->current_cmd_index < cmd->container->size - 1)
	{
		dup2(pipe[out], STDOUT_FILENO);
	}

	set_descriptors(cmd);

	if (_cd == opcode) __cd__(cmd);

	else if (_echo == opcode) __echo__(cmd);

	else if (_env == opcode) __env__(cmd);

	else if (_export == opcode) __export__(cmd);

	else if (_history == opcode) __history__(cmd);

	else if (_pwd == opcode) __pwd__(cmd);

	else if (_unset == opcode) __unset__(cmd);

	else if (_msh_exit == opcode) __exit__(cmd);

	else if (_program == opcode)
	{
		pid_t pid = __fork();

		if (0 == pid)
		{
			close(pipe[in]);
			__eval_prog__(cmd);
		}

		if (_program == opcode && cmd->container->current_cmd_index == cmd->container->size - 1)
		{
			waitpid(pid, &g_exit_status, 0);
			g_exit_status = WEXITSTATUS(g_exit_status);
		}
	}

	dup2(pipe[in], STDIN_FILENO);

	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);

	close(pipe[in]);
	close(pipe[out]);

}
