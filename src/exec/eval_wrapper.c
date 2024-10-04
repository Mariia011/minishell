/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:29:22 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void killall(t_cmd_container *container);
// static void	execute(t_cmd *cmd, t_eval_opcode opcode);

// void	eval_wrapper(t_cmd *cmd, t_eval_opcode opcode)
// {
// 	t_fd	pipes[PIPE_MAX];

// 	if (pipe(pipes) == -1)
// 		return killall(cmd->container);
// 	if (cmd->container->current_cmd_index < cmd->container->size - 1)
// 		dup2(pipes[out], STDOUT_FILENO);
// 	set_descriptors(cmd);
// 	execute(cmd, opcode);
// 	dup2(pipes[in], STDIN_FILENO);
// 	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
// 	close(pipes[in]);
// 	close(pipes[out]);
// }

// static void	execute(t_cmd *cmd, t_eval_opcode opcode)
// {
// 	if (_nonivokable == opcode)
// 		__errcmd__(cmd);
// 	else if (_cd == opcode)
// 		__cd__(cmd);
// 	else if (_echo == opcode)
// 		__echo__(cmd);
// 	else if (_env == opcode)
// 		__env__(cmd);
// 	else if (_export == opcode)
// 		__export__(cmd);
// 	else if (_history == opcode)
// 		__history__(cmd);
// 	else if (_pwd == opcode)
// 		__pwd__(cmd);
// 	else if (_unset == opcode)
// 		__unset__(cmd);
// 	else if (_msh_exit == opcode)
// 		__exit__(cmd);
// 	else if (_program == opcode)
// 		eval_prog(cmd);
// }

// static void killall(t_cmd_container *container)
// {
// 	size_t	i;

// 	container->arr[container->current_cmd_index]->pid = -1;

// 	i = 0;
// 	while (i < container->current_cmd_index)
// 	{
// 		if (container->arr[i] && container->arr[i]->pid > -1)
// 		{
// 			kill(container->arr[i]->pid, SIGKILL);
// 			waitpid(container->arr[i]->pid, NULL, 0);
// 			container->arr[i]->pid = -1;
// 		}
// 		i++;
// 	}
// 	__perror("fork: Resource temporarily unavailable");
// }
