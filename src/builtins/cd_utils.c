/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:57:53 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/10 21:55:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_minus(int *status, t_cmd *cmd);

void	_chdir(t_cmd *cmd, const char *path, int *status)
{
	char *pwd = _getcwd(cmd->shell);
	if (chdir(path) == -1)
	{
		*status = 1;
		if(!__str_ends_with(pwd, "/../"))
			__va_perror("cd: ", path, ": No such file or directory", NULL);
	}
	__delete_string(&pwd);
}

void	__cd_no_arg__(t_cmd *cmd)
{
	int		status;
	char	*home;

	status = 0;
	home = get_val(cmd->shell->export, "HOME");
	if (!home)
		home = get_val(cmd->shell->export, "__HOME_CACHE__");
	if (!home)
	{
		status = 1;
		__perror("cd: HOME not set");
	}
	else
		_chdir(cmd, home, &status);
	set_exit_status(status);
}

void	__cd_one_arg__(t_cmd *cmd)
{
	int	status;

	status = 0;
	if (find_range(cmd->args, "-", NULL) != NULL)
	{
		cd_minus(&status, cmd);
	}
	else if (find_range(cmd->args, "~", NULL))
	{
		__cd_no_arg__(cmd);
		return ;
	}
	else
		_chdir(cmd, front(cmd->args)->val, &status);
	set_exit_status(status);
}

void	cd_minus(int *status, t_cmd *cmd)
{
	char	*path;

	path = get_val(cmd->shell->export, "OLDPWD");
	if (!path || *path == '\0')
	{
		*status = 1;
		__perror("cd: OLDPWD not set");
	}
	else
	{
		_chdir(cmd, path, status);
		pwd(cmd);
	}
}

void	update_pwd(t_shell *shell, char *oldpwd)
{
	char *pwd	__attribute__((cleanup(__delete_string)));

	pwd = NULL;
	if (!shell || !oldpwd)
		return ;
	pwd = _getcwd(shell);
	export_update(shell, "OLDPWD", oldpwd);
	export_update(shell, "PWD", pwd);
	if (__str_ends_with(pwd, "/../"))
		__perror("cd: error retrieving current directory: getcwd:"
			"cannot access parent directories: No such file or directory");
}
