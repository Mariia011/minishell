/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:02:29 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:18:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__exit(const char *const err)
{
	if (NULL != err)
	{
		write(STDERR_FILENO, RED, __strlen(RED));
		write(STDERR_FILENO, "./minishell: ", __strlen("./minishell: "));
		write(STDERR_FILENO, err, __strlen(err));
		write(STDERR_FILENO, "\n", __strlen("\n"));
		write(STDERR_FILENO, RESET, __strlen(RESET));
	}
	exit(EXIT_FAILURE);
}
