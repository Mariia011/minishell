/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 16:14:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

// void eval(t_command *cmd)
// {
// 	pid_t pid = __fork();

// 	push_front(cmd->args, NULL);

// 	t_matrix _args __attribute__((cleanup(__matrix_clear))) = make_matrix_from_list(cmd->args);

// 	if (0 == pid)
// 	{

// 	}

// 	wait(NULL);
// }
