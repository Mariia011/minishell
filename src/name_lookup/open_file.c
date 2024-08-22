/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 13:46:54 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PERMISSIONS 0644

t_fd open_file(char *filename, int option)
{
	t_fd fd = -1;

	if (O_RDONLY == option)
		fd = open(filename, O_RDONLY);
	else
		fd = open(filename, option, PERMISSIONS);

	if (-1 == fd)
	{
		scoped_string msg = __make_string(filename, ": ", "no such file or directory"); //remove variable and just write with __perror??
		__perror(msg);
	}

	return fd;
}
