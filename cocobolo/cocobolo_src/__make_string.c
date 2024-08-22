/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __make_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:53:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:36:26 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__make_string_empty(void)
{
	char	*s;

	s = __malloc(1);
	*s = '\0';
	return (s);
}

char	*__unwrapped_make_string__(char *s, ...)
{
	va_list	args;
	char	*arg;
	char	*res;

	if (!s)
		return (NULL);
	va_start(args, s);
	arg = va_arg(args, char *);
	res = __strdup(s);
	while (NULL != arg)
	{
		res = __single_append__(res, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
	return (res);
}

char	*__make_string_from_char(const char c)
{
	char	*s;

	s = __malloc(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*__make_string_from_list(t_node *first, t_node *last)
{
	char	*res;
	t_node	*curr;

	if (!first || !last)
		return (NULL);
	res = __make_string_empty();
	curr = first;
	while (curr && curr->prev != last)
	{
		res = __strappend(res, curr->val, NULL);
		curr = curr->next;
	}
	return (res);
}
