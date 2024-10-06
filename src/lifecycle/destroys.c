/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/07 00:51:19 by kali             ###   ########.fr       */
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
	tree_clear(&shell->orig_values);
	set_clear(&shell->quoted_tokens);
	set_clear(&shell->dollar_tokens);
	ast_clear(&shell->ast);
	__va_close(&shell->stddesc->stdin, &shell->stddesc->stdout,
		&shell->stddesc->stderr, NULL);
	free(shell->stddesc);
	__putstr_fd(LOG_SEPARATOR, shell->logfile);
	close(shell->logfile);
	__delete_string(&shell->prompt);
	free(shell);
	shell = NULL;
}

void	__cmd_arr__(t_cmd **arr)
{
	size_t	i;

	if (NULL == arr)
		return ;
	i = 0;
	while (arr[i])
	{
		__t_cmd__(arr[i]);
		i++;
	}
	free(arr);
}

void	__t_cmd__(t_cmd *cmd)
{
	if (NULL == cmd)
		return ;
	list_clear(&cmd->args);
	list_clear(&cmd->options);
	list_clear(&cmd->tokens);
	// reset_descriptors(cmd);
	// free(cmd->descriptors);
	__delete_string(&cmd->name);
	__delete_string(&cmd->err);
	__delete_string(&cmd->orig_name);
	free(cmd);
}
