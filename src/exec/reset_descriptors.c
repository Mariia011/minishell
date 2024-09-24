/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_descriptors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:24:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 18:51:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	reset_descriptors(t_cmd *cmd)
// {
// 	if (!cmd || !cmd->shell)
// 		return ;
// 	if (cmd->descriptors->stdin != cmd->shell->stddesc->stdin)
// 	{
// 		if (cmd->descriptors->stdin != -1)
// 			close(cmd->descriptors->stdin);
// 		dup2(cmd->shell->stddesc->stdin, STDIN_FILENO);
// 	}
// 	if (cmd->descriptors->stdout != cmd->shell->stddesc->stdout)
// 	{
// 		if (cmd->descriptors->stdout != -1)
// 			close(cmd->descriptors->stdout);
// 		dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
// 	}
// 	if (cmd->descriptors->stderr != cmd->shell->stddesc->stderr)
// 	{
// 		if (cmd->descriptors->stderr != -1)
// 			close(cmd->descriptors->stderr);
// 		dup2(cmd->shell->stddesc->stderr, STDERR_FILENO);
// 	}
// }
