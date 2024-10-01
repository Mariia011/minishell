/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static int	process_infile(t_listnode *token, t_cmd_container *container);
static int	process_outfile(t_listnode *token, t_cmd_container *container);
static int	process_append(t_listnode *token, t_cmd_container *container);
static int	process_heredoc(t_listnode *token, t_cmd_container *container);

int	redirect(t_listnode *token, t_cmd_container *container)
{
	int	x;

	if (!token || !container)
	{
		return (-1);
	}
	if (string_equal(token->val, "<"))
		x = (process_infile(token, container));
	else if (string_equal(token->val, "<<"))
		x = (process_heredoc(token, container));
	else if (string_equal(token->val, ">"))
		x = (process_outfile(token, container));
	else
		x = (process_append(token, container));
	container->fds[get_next_fd_idx(container)] = x;
	return (x);
}

static int	process_infile(t_listnode *token, t_cmd_container *container)
{
	t_fd	fd;

	fd = -1;
	fd = open_file(token->next->val, O_RDONLY);
	return (fd);
}

static int	process_outfile(t_listnode *token, t_cmd_container *container)
{
	t_fd	fd;

	fd = -1;
	fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_TRUNC);
	return (fd);
}

static int	process_heredoc(t_listnode *token, t_cmd_container *container)
{
	t_fd	fd;

	fd = -1;
	fd = make_heredoc(token->next->val, container->shell,
			is_quoted_token(container->shell->quoted_tokens, token->next));
	return (fd);
}

static int	process_append(t_listnode *token, t_cmd_container *container)
{
	t_fd	fd;

	fd = -1;
	fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_APPEND);
	return (fd);
}
#pragma GCC diagnostic pop
