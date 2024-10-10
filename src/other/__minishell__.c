/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:32:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:32:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__minishell__(char **env)
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
				push_back(shell->history, line);
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
