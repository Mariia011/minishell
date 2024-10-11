/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:21:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 11:17:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static size_t	_count_words(char const *s, char *set);
static size_t	_current_len(char const **str, char *set);
static t_matrix	_allocate(char const *str, char *set, size_t const SIZE);
static void		_skip_(char const **str, char *set);

t_matrix	__split(char const *s, char *set)
{
	if (!s)
		__exit("nullptr passed to __split");
	return (_allocate(s, set, _count_words(s, set)));
}

static size_t	_count_words(char const *s, char *set)
{
	size_t	words;
	short	flag;

	words = 0;
	flag = 0;
	_skip_(&s, set);
	while (*s)
	{
		if (__strchr(set, *s) == false)
			flag = 1;
		else if (flag)
		{
			words++;
			flag = 0;
		}
		s++;
	}
	return (flag + words);
}

static size_t	_current_len(char const **str, char *set)
{
	size_t	len;

	len = 0;
	while (**str && __strchr(set, **str) == false)
	{
		len++;
		(*str)++;
	}
	return (len);
}

static void	_skip_(char const **str, char *set)
{
	while (**str && __strchr(set, **str) == true)
		(*str)++;
}

static t_matrix	_allocate(char const *str, char *set, size_t const SIZE)
{
	t_matrix	arr;
	char		*tmp;
	size_t		current_len;
	size_t		i;
	int			j;

	arr = (char **)__malloc((SIZE + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[SIZE] = NULL;
	i = 0;
	while (i < SIZE)
	{
		_skip_(&str, set);
		tmp = (char *)str;
		current_len = _current_len(&str, set);
		arr[i] = (char *)__malloc(current_len + 1);
		arr[i][current_len] = '\0';
		j = -1;
		while (++j < (int)current_len)
			arr[i][j] = tmp[j];
		i++;
	}
	return (arr);
}
