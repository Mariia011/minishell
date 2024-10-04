/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path_lookup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:44:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:12:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	absolute_end(t_cmd *cmd);

int	absolute_path_lookup(t_cmd *cmd)
{
	struct stat	buffer;
	bool		found;
	char		*filename;

	found = false;
	filename = __strdup(cmd->name);
	if (filename[__strlen(filename) - 1] == '/')
		filename[__strlen(filename) - 1] = '\0';
	found = (stat(filename, &buffer) == 0);
	__delete_string(&filename);
	if (found && S_ISDIR(buffer.st_mode))
	{
		cmd->err = __make_string(cmd->name, ": is a directory", NULL);
		cmd->exit_status = 126;
	}
	else if (found && cmd->name[__strlen(cmd->name) - 1] == '/')
	{
		cmd->err = __make_string(cmd->name, ": Not a directory", NULL);
		cmd->exit_status = 126;
	}
	else if (0 == absolute_end(cmd))
		return (0);
	return (-1);
}

static int	absolute_end(t_cmd *cmd)
{
	if (0 == access(cmd->name, F_OK | X_OK))
	{
		return (0);
	}
	if (0 == access(cmd->name, F_OK))
	{
		cmd->exit_status = 126;
		cmd->err = __make_string(cmd->name, ": Permission denied", NULL);
	}
	else
	{
		cmd->exit_status = 127;
		cmd->err = __make_string(cmd->name, ": No such file or directory",
				NULL);
	}
	return (-1);
}
