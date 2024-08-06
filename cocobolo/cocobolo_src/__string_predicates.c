/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_predicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:14:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 17:12:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool string_less(char *lhv, char *rhv)
{
	return (__strcmp(lhv, rhv) < 0);
}

bool string_greater(char *lhv, char *rhv)
{
	return string_less(rhv, lhv);
}

bool string_equal(char *lhv, char *rhv)
{
	return (__strcmp(lhv, rhv) == 0);
}