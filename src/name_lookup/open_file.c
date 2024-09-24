/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:13:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PERMISSIONS 0644

t_fd	open_file(char *filename, int option)
{
	t_fd	fd;

	fd = -1;
	if (O_RDONLY == option)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, option, PERMISSIONS);
	if (-1 == fd)
	{
		__va_perror(filename, ": ", "no such file or directory", NULL);
	}
	return (fd);
}
