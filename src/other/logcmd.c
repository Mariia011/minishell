/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:36:02 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 00:36:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void logcmd(const char * line, t_fd logfile)
{
	static size_t x = 1;

	char *out __attribute__((cleanup(__delete_string))) = __itoa((int)x++);

	out = __strappend(out, ". ", line, NULL);

	__putendl_fd(out, logfile);
}
