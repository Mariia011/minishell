/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_vol_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:42:17 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:23:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*make_list_from_matrix(char **arr)
{
	t_list	*list;
	size_t	i;

	if (NULL == arr)
		__exit("nullptr passed to make_list_from_matrix");
	list = make_list();
	i = 0;
	while (arr[i])
	{
		push_back(list, arr[i]);
		i++;
	}
	return (list);
}

static t_list	*make_list_from_string_all(char *s, char *set)
{
	t_list	*list;
	char	*val;
	char	*tmp;

	list = make_list();
	while (*s)
	{
		if (__strchr(set, *s) == true)
		{
			val = __make_string_from_char(*s);
			push_back(list, val);
			++s;
		}
		else
		{
			tmp = s + 1;
			while (*tmp && __strchr(set, *tmp) == false)
				tmp++;
			val = __strdup_until(s, *tmp);
			push_back(list, val);
			s = tmp;
		}
		__delete_string(&val);
	}
	return (list);
}

t_list	*make_list_from_string(char *s, char *set, t_opcode opcode)
{
	t_matrix	arr;
	t_list		*res;

	arr = NULL;
	if (words_only == opcode)
	{
		arr = __split(s, set);
		res = make_list_from_matrix(arr);
		matrix_clear(&arr);
		return (res);
	}
	return (make_list_from_string_all(s, set));
}
