/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:07:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	__unset_var__(t_shell *shell, t_list_value key)
{
	if (!key)
		return (-1);
	if (!is_name(key))
	{
		__va_perror("unset: `", key, "\': not a valid identifier", NULL);
		return (-1);
	}
	unset_var(shell, key);
	return (0);
}

void	unset_var(t_shell *shell, t_list_value key)
{
	if (!key)
		return ;
	tree_remove(shell->export, key);
	tree_remove(shell->env, key);
}

static void	_unset_args(t_listnode *arg, t_cmd *cmd, int *status)
{
	while (arg)
	{
		if (-1 == __unset_var__(cmd->shell, arg->val))
			*status = 1;
		arg = arg->next;
	}
}

void	unset(t_cmd *cmd)
{
	int			status;
	t_listnode	*arg;

	if (!cmd || !cmd->args)
		return ;
	status = 0;
	arg = front(cmd->args);
	if (!empty(cmd->options))
	{
		__va_perror("unset: ", front(cmd->options)->val, ": invalid option",
			NULL);
		status = 1;
	}
	else
		_unset_args(arg, cmd, &status);
	set_exit_status(status);
}
