/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 19:09:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*make_command(char *raw_cmd, t_shell *shell)
{
	t_cmd		*cmd;
	t_node		*possible_name;

	t_list		*tokens;

	tokens = preprocess(tokenize(raw_cmd), shell);
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
	cmd->redirection = 0;
	possible_name = tokens->head;
	while (possible_name && possible_name->next && is_redir(possible_name))
	{
		possible_name = possible_name->next->next;
	}

	bool no_name = (possible_name == NULL);

	if (!no_name)
	{
		cmd->name = __strdup(possible_name->val);
		cmd->orig_name = __strdup(possible_name->val);
	}

	wildcard_resolve(tokens, shell);

	// add redirection handling
	if (no_name || empty(tokens)
		|| sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		__t_command__(cmd);
		cmd = NULL;
	}
	list_clear(&tokens);
	return (cmd);
}
