/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 16:06:09 by aamirkha         ###   ########.fr       */
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
		t_list * tokens = preprocess(tokenize(line), shell);
		t_cmd** arr = make_cmd_arr(tokens, shell);
		// cmd = make_command(tokens, shell);
		if (line)
		{
			for (int i = 0; arr[i]; i++)
				eval(arr[i]);
			if (__strlen(line) > 0)
			{
				push_back(shell->history, line);
				add_history(line);

				logcmd(line, shell->logfile);
			}
		}
		__cmd_arr__(arr);
		list_clear(&tokens);
		// __t_cmd__(cmd);
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
