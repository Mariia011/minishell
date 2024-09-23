/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:33:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:20:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	va_push_back(t_list *list, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, list);
	arg = va_arg(args, char *);
	while (NULL != arg)
	{
		push_back(list, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
}

void	va_push_front(t_list *list, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, list);
	arg = va_arg(args, char *);
	while (NULL != arg)
	{
		push_front(list, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
}
