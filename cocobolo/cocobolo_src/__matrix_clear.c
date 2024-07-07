/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __matrix_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:04:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 01:07:10 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void __matrix_clear(t_matrix *arrptr)
{
    t_matrix arr = *arrptr;

    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    *arrptr = NULL;
}