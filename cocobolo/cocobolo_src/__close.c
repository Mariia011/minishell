/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:57:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:18:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__va_close(int *s, ...)
{
	va_list	args;
	int		*fdptr;

	if (!s)
		return ;
	close(*s);
	va_start(args, s);
	fdptr = va_arg(args, int *);
	while (NULL != fdptr)
	{
		close(*fdptr);
		fdptr = va_arg(args, int *);
	}
	va_end(args);
}
