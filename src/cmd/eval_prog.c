/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:03:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eval_prog(t_cmd *cmd)
{
	int	s;

	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		cmd->pid = -1;
		killall(cmd->shell->ast);
		return ;
	}
	if (0 == cmd->pid)
	{
		eval_prog_core(cmd);
	}
}

void	eval_prog_core(t_cmd *cmd)
{
	t_list		*options_copy;
	t_list		*args_copy;
	t_matrix	_args;
	t_matrix	_env;

	if (!cmd)
		exit(EXIT_FAILURE);
	options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name);
	args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);
	_args = make_matrix_from_list(options_copy);
	_env = make_matrix_from_tree(cmd->shell->env);
	execve(cmd->name, _args, _env);
	__t_shell__(cmd->shell);
	exit(EXIT_FAILURE);
}
