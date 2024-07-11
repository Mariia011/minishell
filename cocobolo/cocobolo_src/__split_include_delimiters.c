/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __split_include_delimiters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:52:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 21:09:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

t_matrix  __result_use_check  __split_include_delimiters(char const *s, char c)
{
	t_matrix __dtor(__matrix_clear) arr = __split(s, c);

	size_t SIZE = __matrix_size(arr) * 2 - 1;

	t_matrix res = malloc(sizeof(char *) * (SIZE + 1));

	res[SIZE] = NULL;

	size_t i = 0;
	size_t j = 0;

	while (i < SIZE)
	{
		res[i] = __strdup(arr[j]);
		if (i + 1 < SIZE)
		{
			res[i + 1] = __malloc(2);
			res[i + 1][0] = c;
			res[i + 1][1] = '\0';
		}
		i += 2;
		j++;
	}
	return res;
}