/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:25:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 00:31:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void errcmd(t_cmd *cmd)
// {
// 	eval_wrapper(cmd, _nonivokable);
// }

void errcmd(t_cmd *cmd)
{
	if (NOT_FOUND == cmd->exit_status)
		__va_perror(cmd->name, ": command not found", NULL);
	set_exit_status_no_of(cmd->exit_status);
}