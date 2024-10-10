/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:25:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:06:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	errcmd(t_cmd *cmd)
{
	__perror(cmd->err);
	set_exit_status_no_of(cmd->exit_status);
}
