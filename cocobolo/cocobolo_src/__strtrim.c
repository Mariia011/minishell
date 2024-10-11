/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strtrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:19:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 11:14:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static void	_move_ptrs(char **left, char **right, char *set);

char	*__strtrim(char *s1, char *set)
{
	char	*left;
	char	*right;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	left = (char *)s1;
	right = ((char *)s1) + __strlen(s1) - 1;
	_move_ptrs(&left, &right, set);
	if (left > right)
		return (__make_string_empty());
	res = __strdup(left);
	res[right - left + 1] = '\0';
	return (res);
}

static void	_move_ptrs(char **left, char **right, char *set)
{
	while (((*left)) && __strchr(set, **left))
		++(*left);
	while (((*right) >= (*left)) && __strchr(set, **right))
		--(*right);
}
