/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_orig_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:18:09 by kali              #+#    #+#             */
/*   Updated: 2024/10/07 00:20:38 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_orig_val(t_listnode *token, t_shell *shell)
{
	char *guess	__attribute__((cleanup(__delete_string)));

	guess = NULL;
	if (!shell || !token)
		return (false);
	guess = __ptoa((size_t)token);
	return (get_val(shell->orig_values, guess));
}
