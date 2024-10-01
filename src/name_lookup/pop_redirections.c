/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:37:08 by codespace         #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	take_infile(t_cmd *cmd, char *val, t_list *tokens);
// static int	take_outfile(t_cmd *cmd, t_list *tokens);

// int	pop_redirections(t_cmd *cmd, t_list *tokens, t_cmd_container *container)
// {
// 	t_listnode	*token;
// 	t_listnode	*next;
// 	t_fd	fd;

// 	token = tokens->head;
// 	while (token)
// 	{
// 		next = token->next;
// 		if (is_redirection(token->val)
// 			&& !is_quoted_token(container->shell->quoted_tokens, token))
// 		{
// 			next = token->next->next;
// 			fd = -1337;
// 			if (string_equal(token->val, "<") || string_equal(token->val, "<<"))
// 				fd = take_infile(cmd, token->val, tokens);
// 			if (string_equal(token->val, ">") || string_equal(token->val, ">>"))
// 				fd = take_outfile(cmd, tokens);
// 			if (fd == -1)
// 			{
// 				get_next_fd_idx(NULL);
// 				return (-1);
// 			}
// 			erase(tokens, token, token->next);
// 		}
// 		token = next;
// 	}
// 	get_next_fd_idx(NULL);
// 	return (0);
// }

// static int	take_infile(t_cmd *cmd, char *val, t_list *tokens)
// {
// 	int	fd;

// 	fd = get_next_fd(cmd->container);
// 	close(cmd->descriptors->stdin);
// 	cmd->descriptors->stdin = fd;
// 	cmd->redirection |= redirect_in;
// 	if (string_equal(val, "<<"))
// 		cmd->redirection |= redirect_heredoc;
// 	return (fd);
// }
// static int	take_outfile(t_cmd *cmd, t_list *tokens)
// {
// 	int	fd;

// 	fd = get_next_fd(cmd->container);
// 	close(cmd->descriptors->stdout);
// 	cmd->descriptors->stdout = fd;
// 	cmd->redirection |= redirect_out;
// 	return (fd);
// }
