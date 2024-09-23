/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path_lookup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:44:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:06:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	absolute_path_lookup(t_cmd *cmd)
{
	struct stat buffer;

	bool found = false;

	char * filename = __strdup(cmd->name);

	if (filename[__strlen(filename) - 1] == '/') filename[__strlen(filename) - 1] = '\0';

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

	else
	{
		if (0 == access(cmd->name, F_OK | X_OK))
		{
			cmd->eval = eval_prog_preprocess;
			return 0;
		}
		if (0 == access(cmd->name, F_OK))
		{
			cmd->exit_status = 126;
			cmd->err = __make_string(cmd->name, ": Permission denied", NULL);
		}
		else
		{
			cmd->exit_status = 127;
			cmd->err = __make_string(cmd->name, ": No such file or directory", NULL);
		}
	}

	return (-1);
}
