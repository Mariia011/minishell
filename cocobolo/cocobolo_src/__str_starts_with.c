/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str_starts_with.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:36:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/10 15:00:22 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool	__str_starts_with(const char *haystack, char *needle)
{
	if (!haystack || !needle || __strlen(haystack) < __strlen(needle))
		return (false);
	return (__strcmp_weak__(haystack, needle));
}