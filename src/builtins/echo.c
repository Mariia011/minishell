/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 21:23:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(t_command *cmd)
{
	if (!cmd) return;

	t_node *node = cmd->args->head;

	while (node)
	{
		printf("%s", node->val);
		if (node->next) printf(" ");
		node = node->next;
	}

	if (NULL == find_range(cmd->options, "-n", NULL))
		printf("\n");
}
