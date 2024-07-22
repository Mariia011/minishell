/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_desciptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:09:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/22 23:23:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_descriptor * __result_use_check make_descriptors()
{
	t_descriptor *descriptor = __malloc(sizeof(t_descriptor));
	descriptor->stdout = 1488;
	descriptor->stdin = 1337;
	descriptor->stderr = 6969;
	dup2(STDOUT_FILENO, descriptor->stdout);
	dup2(STDIN_FILENO, descriptor->stdin);
	dup2(STDERR_FILENO, descriptor->stderr);

	return descriptor;
}
