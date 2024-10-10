/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_desciptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:09:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:08:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_descriptor	*make_descriptors(void)
{
	static int		__fd = 999;
	t_descriptor	*descriptor;

	descriptor = __malloc(sizeof(t_descriptor));
	descriptor->stdout = ++__fd;
	descriptor->stdin = ++__fd;
	descriptor->stderr = ++__fd;
	return (descriptor);
}

t_descriptor	*make_stddesc(void)
{
	t_descriptor	*res;

	res = make_descriptors();
	res->stdout = dup(STDOUT_FILENO);
	res->stdin = dup(STDIN_FILENO);
	res->stderr = dup(STDERR_FILENO);
	return (res);
}
