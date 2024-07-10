/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 23:23:10 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

int redirect(t_node *token)
{
	if (!token || !token->next)
	{
		__exit ("bad redirections parse");
	}

	// if (access(token->next->val, F_OK | R_OK) == -1)
	// {
	// 	perror("redirection error");
	// 	return -1;
	// }

	t_file fd = -1;

	if (0 == __strcmp(token->val, "<"))
	{
		fd = open_file(token->next->val, O_RDONLY);
		if (fd == -1) return -1;
		close(shell->infile);
		shell->descriptors->stdin = fd;
		shell->infile = fd;
		// dup2(shell->infile, STDIN_FILENO);
	}
	else
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1) return -1;
		close(shell->outfile);
	shell->descriptors->stdout = fd;
		shell->outfile = fd;
		// dup2(shell->outfile, STDOUT_FILENO);
	}
	return 0;
}
