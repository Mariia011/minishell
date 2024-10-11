/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:32:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 16:04:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__minishell__(int __attribute__((unused)) ac,
			char __attribute__((unused)) **av, char **env)
{
	t_shell	*shell;
	char	*line;

	shell = make_shell(env);
	while (true)
	{
		line = read_line(shell->prompt);
		shell->ast = make_ast(line, shell);
		if (line)
		{
			ast_eval(shell->ast);
			if (__strlen(line) > 0)
			{
				add_history(line);
			}
		}
		ast_clear(&shell->ast);
		if (!line)
			break ;
		__delete_string(&line);
	}
	__t_shell__(shell);
	printf("exit\n");
}
