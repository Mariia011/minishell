/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 21:40:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	echo(t_command *cmd)
{
	eval_wrapper(cmd, _echo);
}

void	__echo__(t_command *cmd)
{
	bool	newline;

	if (!cmd)
		return ;
	newline = true;
	if (!empty(cmd->options) && is_n(front(cmd->options)->val))
	{
		newline = false;
		erase(cmd->options, front(cmd->options), find_if(front(cmd->options),
				back(cmd->options), last_nl));
	}
	if (!empty(cmd->options))
		push_back(cmd->options, "", NULL);
	echo_arglist(cmd->options);
	echo_arglist(cmd->args);
	if (newline)
		printf("\n");
	set_exit_status(0);
}

#pragma GCC diagnostic pop
