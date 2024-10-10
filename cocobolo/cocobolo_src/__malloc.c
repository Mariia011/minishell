/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:03:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:19:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	*__malloc(size_t n)
{
	void	*ptr;

	ptr = malloc(n);
	if (NULL == ptr)
		__exit("Bad alloc");
	return (ptr);
}

void	*__calloc(size_t n)
{
	void	*ptr;

	ptr = malloc(n);
	if (NULL == ptr)
		__exit("Bad alloc");
	__memset(ptr, 0, n);
	return (ptr);
}
