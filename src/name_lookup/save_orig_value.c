/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_orig_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:21:44 by kali              #+#    #+#             */
/*   Updated: 2024/10/07 00:24:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_orig_value(t_listnode *address, t_shell *shell)
{
	char	*val;

	val = __ptoa((size_t)address);
	tree_update(shell->orig_values, val, address->val);
	free(val);
}
