/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:36:02 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:06:10 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	logcmd(const char *line, t_fd logfile)
{
	static size_t	x = 1;
	char			*out;

	out = __itoa((int)x++);
	out = __strappend(out, ". ", line, NULL);
	__putendl_fd(out, logfile);
	__delete_string(&out);
}
