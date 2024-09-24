/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 18:51:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	set_descriptors(t_cmd *cmd)
// {
// 	if (!cmd)
// 		return ;
// 	if (cmd->redirection & redirect_in)
// 		dup2(cmd->descriptors->stdin, STDIN_FILENO);
// 	if (cmd->redirection & redirect_out)
// 		dup2(cmd->descriptors->stdout, STDOUT_FILENO);
// }
