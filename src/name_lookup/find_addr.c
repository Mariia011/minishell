/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:17:27 by kali              #+#    #+#             */
/*   Updated: 2024/10/07 00:19:13 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	find_addr(t_set *set, t_listnode *token)
{
	char *guess	__attribute__((cleanup(__delete_string)));

	guess = NULL;
	if (!set || !token)
		return (false);
	guess = __ptoa((size_t)token);
	return (set_count(set, guess) != 0);
}
