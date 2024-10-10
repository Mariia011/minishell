/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:11:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:59:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	waitcmd(pid_t pid, int *x)
{
	*x = 0;
	waitpid(pid, x, 0);
	if (WIFSIGNALED(*x))
	{
		*x = WTERMSIG(*x) + 128;
		if (*x == 131)
			printf("Quit: 3\n");
		set_exit_status(*x);
	}
	else
		set_exit_status(WEXITSTATUS(*x));
}
