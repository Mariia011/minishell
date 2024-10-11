/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 10:26:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*make_command_core(t_list *tokens, t_shell *shell);

t_cmd	*make_command(t_list *tokens, t_shell *shell)
{
	t_cmd		*cmd;
	t_listnode	*possible_name;

	if (empty(tokens) || !shell)
	{
		if (empty(tokens))
			list_clear(&tokens);
		return (NULL);
	}
	cmd = make_command_core(tokens, shell);
	return (cmd);
}

static t_cmd	*make_command_core(t_list *tokens, t_shell *shell)
{
	t_cmd		*cmd;

	cmd = __calloc(sizeof(t_cmd));
	cmd->tokens = tokens;
	cmd->shell = shell;
	cmd->pid = -1337;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->eval = NULL;
	cmd->err = NULL;
	cmd->invokable = true;
	cmd->forkable = false;
	cmd->redirection = 0;
	cmd->exit_status = 0;
	return (cmd);
}
