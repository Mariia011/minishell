/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_predicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:14:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/10 15:01:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool	string_less(const char *lhv, const char *rhv)
{
	return (__strcmp(lhv, rhv) < 0);
}

bool	string_greater(const char *lhv, const char *rhv)
{
	return (string_less(rhv, lhv));
}

bool	string_equal(const char *lhv, const char *rhv)
{
	return (__strcmp(lhv, rhv) == 0);
}
