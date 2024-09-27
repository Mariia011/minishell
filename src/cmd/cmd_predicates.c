/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_predicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:21:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 19:25:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_invokable(t_cmd *cmd)
{
	return (cmd->invokable);
}

bool is_program(t_cmd *cmd)
{
	return (cmd->eval == eval_prog || cmd->forkable == true);
}
