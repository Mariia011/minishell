/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocobolo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 21:45:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COCOBOLO_H
# define COCOBOLO_H

# include "optional.h"
# include "list.h"
# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define P(a) printf(a)

void		__exit(char const *const err) __attribute__((noreturn));
t_optional	__atoi(char const *str);
void		*__malloc(size_t n) __attribute__((malloc));

#endif // COCOBOLO_H
