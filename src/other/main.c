/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 00:36:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pipe parse has to be formatted for || OR operator
//  add & as a special symbol

int	main(int ac, char **av, char **env)
{
	t_shell			*shell;
	char			*line;
	t_cmd			*cmd;


	shell = make_shell(env);
	while (true)
	{
		line = read_line(shell->prompt);
		cmd = make_command(line, shell);
		if (line)
		{
			eval(cmd);
			if (__strlen(line) > 0)
			{
				push_back(shell->history, line, NULL);
				add_history(line);

				logcmd(line, shell->logfile);

			}
		}
		__t_command__(cmd);
		if (!line)
			break;
		__delete_string(&line);
	}
	// char *__pid __attribute__((cleanup(__delete_string))) = get_pid(shell);

	// char *lsof __attribute__((cleanup(__delete_string))) = __make_string("lsof -p ", __pid, " -a -d 0-256", NULL);

	__t_shell__(shell);

	// system(lsof);

	printf("exit\n");
	return (get_exit_status());
}

// #ifdef __APPLE__
// void	__attribute__((destructor)) moid(void)
// {
// 	// printf(GREEN);
// 	printf("\n\nLeaks report\n");
// 	system("leaks minishell");
// 	// printf(RESET);
// }
// #endif // __APPLE__
