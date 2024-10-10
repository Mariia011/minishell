/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:07:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	__print_export__(t_tree_node *node);

void	export(t_cmd *cmd)
{
	int			status;
	t_listnode	*arg;

	if (!cmd)
		return ;
	status = 0;
	if (empty(cmd->args) && empty(cmd->options))
	{
		print_tree_inorder_custom(cmd->shell->export, __print_export__);
	}
	else if (invalid_option(cmd) == -1)
		status = 2;
	else
	{
		arg = front(cmd->args);
		while (arg)
		{
			if (-1 == __export_from_string__(arg->val, cmd->shell))
				status = 1;
			arg = arg->next;
		}
	}
	set_exit_status(status);
}

int	export_update(t_shell *shell, t_list_value key, t_list_value val)
{
	if (!shell || !key)
		return (-1);
	unset_var(shell, key);
	tree_update(shell->export, key, val);
	if (val)
		tree_update(shell->env, key, val);
	return (0);
}

static void	__print_export__(t_tree_node *node)
{
	if (!node)
		return ;
	printf("%s", DECLAREX);
	printf("%s", node->key);
	if (node->val)
		printf("=\"%s\"", node->val);
	printf("\n");
}
