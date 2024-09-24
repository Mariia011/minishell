/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:21:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eval_prog_preprocess(t_cmd *cmd)
{
	int		s;

	cmd->pid = fork();
	// if (cmd->pid < 0)
	// {
	// 	cmd->pid = -1;
	// 	return killall(cmd->container);
	// }
	if (0 == cmd->pid)
	{
		eval_prog(cmd);
	}
	// if (cmd->container->current_cmd_index == cmd->container->size - 1)
	// {
	// 	waitpid(cmd->pid, &s, 0);
	// 	if (WIFSIGNALED(s))
	// 	{
	// 		s = WTERMSIG(s) + 128;
	// 		if (s == 131)
	// 			printf("Quit: 3\n");
	// 		set_exit_status(s);
	// 	}
	// 	else
	// 		set_exit_status(WEXITSTATUS(s));
	// }
}

// void	eval_prog(t_cmd *cmd)
// {
// 	eval_wrapper(cmd, _program);
// }

void	eval_prog(t_cmd *cmd)
{
	t_list		*options_copy;
	t_list		*args_copy;
	t_matrix	_args;
	t_matrix	_env;

	if (!cmd)
		__exit(NULL);
	options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name);

	args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);
	_args = make_matrix_from_list(options_copy);
	_env = make_matrix_from_tree(cmd->shell->env);

	execve(cmd->name, _args, _env);
	__t_shell__(cmd->shell);
	__exit(NULL);
}
