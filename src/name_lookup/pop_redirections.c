/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:37:08 by codespace         #+#    #+#             */
/*   Updated: 2024/10/04 15:57:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	take_infile(t_cmd *cmd, char *val, t_list *tokens);
// static int	take_outfile(t_cmd *cmd, t_list *tokens);

int	pop_redirections(t_list *partition, t_shell *shell)
{
	t_listnode	*token;
	t_listnode	*next;

	token = partition->head;
	while (token)
	{
		next = token->next;
		if (is_redirection_token(token, shell))
		{
			erase(partition, token, token->next);
		}
		token = next;
	}
	return (0);
}

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
