/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_logfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:43:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 15:12:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef __linux__
#define DATE "/usr/bin/date"
#elif defined __APPLE__
#define DATE "/bin/date"
#endif

t_fd make_logfile(t_shell *shell)
{
	t_fd res =  open_file("log.txt", O_WRONLY | O_APPEND | O_CREAT);

	char		*cmd[2];

	cmd[0] = DATE;
	cmd[1] = NULL;
	pid_t pid = __fork();
	if (pid == 0)
	{
		dup2(res, STDOUT_FILENO);
		close(res);
		execve(cmd[0], cmd, NULL);
		__t_shell__(shell);
		exit(EXIT_FAILURE);
	}

	wait(NULL);

	char *username __attribute__((cleanup(__delete_string))) =

		__make_string("\n", get_val(shell->export, "USER"), "\n", NULL);

	__putendl_fd(username, res);

	return res;
}
