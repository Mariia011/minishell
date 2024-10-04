/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:36:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:04:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history(t_cmd *cmd)
{
	if (!cmd || !cmd->shell)
		return ;
	print_list_enumerate(cmd->shell->history);
}
