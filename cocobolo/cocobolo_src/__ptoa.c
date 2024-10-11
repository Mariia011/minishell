/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ptoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:01:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 11:16:09 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static size_t	_digit_count(size_t const n);
static size_t	_calculate_size(size_t const n);
static char		_to_char(size_t n);
static char		*_allocate(size_t n);

char	*__ptoa(size_t n)
{
	return (_allocate(n));
}

static size_t	_digit_count(size_t const n)
{
	if (n == 0)
		return (0);
	return (1 + _digit_count(n / 10));
}

static size_t	_calculate_size(size_t const n)
{
	if (n == 0)
		return (1);
	return (_digit_count(n));
}

static char	_to_char(size_t n)
{
	return (n + '0');
}

static char	*_allocate(size_t n)
{
	char	*dst;
	size_t	size;

	size = _calculate_size(n);
	dst = __malloc(size + 1);
	if (!dst)
		return (NULL);
	dst[size] = '\0';
	while (size > 0)
	{
		dst[size - 1] = _to_char(n % 10);
		n /= 10;
		size--;
	}
	return (dst);
}
