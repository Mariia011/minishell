/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 19:38:50 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*make_command(t_list *tokens, t_shell *shell)
{
	t_cmd		*cmd;
	t_node		*possible_name;

	if (empty(tokens) || !shell)
		return (NULL);


	if (count_range(tokens, "<<") > HEREDOC_MAX)
	{
		list_clear(&tokens);
		__t_shell__(shell);
		__perror("maximum here-document count exceeded");
		exit(2);
	}

	cmd = __calloc(sizeof(t_cmd));
	cmd->tokens = tokens;
	// cmd->descriptors = make_stddesc();
	cmd->shell = shell;
	cmd->pid = -1337;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->eval = NULL;
	cmd->err = NULL;
	cmd->invokable = true;
	cmd->redirection = 0;
	cmd->exit_status = 0;

	cmd->name = __strdup(tokens->head->val);
	cmd->orig_name = __strdup(tokens->head->val);

	wildcard_resolve(tokens, shell);

	// add redirection handling
	if (empty(tokens) || sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		cmd->invokable = false;
	}
	return (cmd);
}
