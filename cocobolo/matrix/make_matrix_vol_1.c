/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix_vol_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:23:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

t_matrix	make_matrix_from_string(char *s, char *set)
{
	return (__split(s, set));
}

t_matrix	make_matrix_copy(t_matrix other)
{
	size_t		i;
	t_matrix	res;

	if (!other)
		return (NULL);
	i = 0;
	while (other[i])
		i++;
	res = malloc(i + 1);
	res[i] = NULL;
	i = 0;
	while (other[i])
	{
		res[i] = __strdup(other[i]);
		i++;
	}
	return (res);
}

t_matrix	make_matrix_from_list(t_list *list)
{
	size_t		lstsize;
	t_matrix	arr;
	t_listnode	*node;
	size_t		i;

	if (!list)
		return (NULL);
	lstsize = size(list);
	arr = __malloc(sizeof(char *) * (lstsize + 1));
	arr[lstsize] = NULL;
	node = front(list);
	i = 0;
	while (node)
	{
		arr[i] = __strdup(node->val);
		node = node->next;
		i++;
	}
	return (arr);
}
