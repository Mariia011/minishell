/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 13:45:18 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

extern int	g_exit_status;

int	redirect(t_node *token, t_command *cmd)
{
	t_fd	fd;

	fd = -1;
	if (string_equal(token->val, "<"))
	{
		fd = open_file(token->next->val, O_RDONLY);
		if (fd == -1)
			return (-1);
		cmd->descriptors->stdin = fd;
		cmd->redirection |= redirect_in;
	}
	else if (string_equal(token->val, "<<"))
	{
		fd = make_heredoc(token->next->val, cmd->shell,
				is_quoted_token(cmd->shell->quoted_tokens, token->next));
		if (fd == -1)
			return (-1);
		cmd->descriptors->stdin = fd;
		cmd->redirection |= redirect_in | redirect_heredoc;
	}
	else if (string_equal(token->val, ">"))
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1)
			return (-1);
		cmd->descriptors->stdout = fd;
		cmd->redirection |= redirect_out;
	}
	else
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_APPEND);
		if (fd == -1)
			return (-1);
		cmd->descriptors->stdout = fd;
		cmd->redirection |= redirect_out;
	}
	return (0);
}

#pragma GCC diagnostic pop
