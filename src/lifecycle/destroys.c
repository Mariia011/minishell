/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 00:59:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__t_shell__(t_shell *shell)
{
	if (NULL == shell)
		return ;
	list_clear(&shell->history);
	tree_clear(&shell->env);
	tree_clear(&shell->export);
	set_clear(&shell->quoted_tokens);
	__va_close(&shell->stddesc->stdin, &shell->stddesc->stdout, &shell->stddesc->stderr, NULL);
	free(shell->stddesc);
	__putstr_fd(LOG_SEPARATOR, shell->logfile);
	close(shell->logfile);
	__delete_string(&shell->prompt);
	free(shell);
	shell = NULL;
}

void	__t_command__(t_cmd *cmd)
{
	if (NULL == cmd)
		return ;
	if (cmd->redirection & redirect_heredoc)
		unlink(HEREDOC);
	list_clear(&cmd->args);
	list_clear(&cmd->options);
	// list_clear(&cmd->tokens);
	// reset_descriptors(cmd);
	// free(cmd->descriptors);
	__delete_string(&cmd->name);
	__delete_string(&cmd->err);
	__delete_string(&cmd->orig_name);
	free(cmd);
}

void	__t_cmd_container__(t_cmd_container **cmdsptr)
{
	t_cmd_container	*cmds;
	size_t			i;

	if (NULL == cmdsptr)
		return ;
	cmds = *cmdsptr;
	if (NULL == cmds)
		return ;
	i = 0;
	while (i < cmds->size)
	{
		__t_command__(cmds->arr[i]);
		i++;
	}
	set_clear(&cmds->shell->quoted_tokens);
	cmds->shell->quoted_tokens = make_set();
	list_clear(&cmds->tokens);
	get_next_fd(NULL);
	get_next_fd_idx(NULL);
	cmds->shell = NULL;
	free(cmds->arr);
	free(cmds->fds);
	free(cmds);
	// *cmdsptr = NULL;
}
