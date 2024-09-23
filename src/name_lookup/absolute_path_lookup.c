/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path_lookup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:44:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 00:31:24 by aamirkha         ###   ########.fr       */
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
		__va_perror(cmd->name, ": is a directory", NULL);
		set_exit_status(126);
	}
	else if (found && cmd->name[__strlen(cmd->name) - 1] == '/')
	{
		__va_perror(cmd->name, ": Not a directory", NULL);
		set_exit_status(126);
	}

	else
	{
		if (0 == access(cmd->name, F_OK | X_OK))
		{
			cmd->eval = eval_prog_preprocess;
			return 0;
		}
		if (0 == access(cmd->name, F_OK))
			__va_perror(cmd->name, ": Permission denied", NULL);
		else
			__va_perror(cmd->name, ": No such file or directory", NULL);
	}

	return (-1);
}
