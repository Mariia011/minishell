/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 23:48:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	cd(t_cmd *cmd)
// {
// 	eval_wrapper(cmd, _cd);
// }

void	cd(t_cmd *cmd)
{
	char	*msg;
	char	*oldpwd;

	if (!cmd)
		return ;
	if (size(cmd->options) > 1 || (size(cmd->options) == 1
			&& !string_equal(front(cmd->options)->val, "-")))
	{
		set_exit_status(2);
		msg = __make_string("cd: ", front(cmd->options)->val,
				": invalid option", NULL);
		__perror(msg);
		__delete_string(&msg);
		return ;
	}
	list_move_back(cmd->options, cmd->args);
	oldpwd = get_val(cmd->shell->export, "PWD");
	if (empty(cmd->args))
		__cd_no_arg__(cmd);
	else
		__cd_one_arg__(cmd);
	update_pwd(cmd->shell, oldpwd);
}
