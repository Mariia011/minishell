/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:04:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *cmd)
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
		push_back(cmd->options, "");
	echo_arglist(cmd->options);
	echo_arglist(cmd->args);
	if (newline)
		printf("\n");
	set_exit_status(0);
}
