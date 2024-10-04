/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __putendl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:17 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:19:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

ssize_t	__putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (-1);
	return (write(fd, s, __strlen(s)) + write(fd, "\n", 1));
}
