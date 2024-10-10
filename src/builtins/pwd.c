/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:19:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:04:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE 4096

void	pwd(t_cmd *cmd)
{
	int		status;
	char	*path;

	status = 0;
	if (invalid_option(cmd))
	{
		status = 1;
	}
	else
	{
		path = __strdup(get_val(cmd->shell->export, "PWD"));
		if (!path || !(*path))
		{
			__delete_string(&path);
			path = _getcwd(cmd->shell);
		}
		printf("%s\n", path);
		__delete_string(&path);
	}
	set_exit_status(status);
}

char	*_getcwd(t_shell *shell)
{
	char	*path;

	path = __malloc(SIZE + 1);
	if (NULL == getcwd(path, SIZE))
	{
		__delete_string(&path);
		path = __make_string(get_val(shell->export, "PWD"), "/../", NULL);
	}
	return (path);
}
