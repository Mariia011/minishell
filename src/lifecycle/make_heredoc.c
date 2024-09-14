/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/15 00:40:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define HEREDOC_PROMPT "heredoc> "

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted);

static void	quit_from_heredoc(int __attribute__((unused)) signal)
{
	set_exit_status(1);
	exit(130);
}

static void	set_signals_heredoc(void)
{
	struct sigaction	act;

	__memset(&act, 0, sizeof(act));
	act.sa_handler = &quit_from_heredoc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	disable_echoctl();
}

t_fd	make_heredoc(char *eof, t_shell *shell, bool is_quoted)
{
	pid_t pid = __fork();
	int res = 0;

	ignore_sigquit();
	if (pid == 0)
	{
		exit(make_heredoc_child(eof, shell, is_quoted));
	}
	waitpid(pid, &res, 0);
	res = WEXITSTATUS(res);
	if (res == 1)
	{
		set_exit_status(1);
		return (-1);
	}
	return open_file(HEREDOC, O_RDONLY);
}

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted)
{
	t_fd	fd;
	char	*line;

	if (!eof || !shell)
		return (-1);
	set_exit_status(0);
	fd = open_file(HEREDOC, O_CREAT | O_RDWR);
	set_signals_heredoc();
	line = readline(HEREDOC_PROMPT);
	while (!string_equal(line, eof) && get_exit_status() == 0)
	{
		line = __strappend(line, "\n", NULL);
		if (!is_quoted && __strchr(line, '$'))
		{
			line = resolve(line, shell);
		}
		__putstr_fd(line, fd);
		free(line);
		line = readline(HEREDOC_PROMPT);
	}
	free(line);
	close(fd);
	__t_cmd_container__(&shell->container);
	__t_shell__(shell);
	return (get_exit_status());
}
