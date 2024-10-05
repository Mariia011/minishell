/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/05 19:47:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define HEREDOC_PROMPT "heredoc> "

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted);
static void __cleanup__(const int _fd, t_shell *_shell, enum e_cleanup_option opt);

static void	quit_from_heredoc(int __attribute__((unused)) signal)
{
	__cleanup__(0, NULL, delete);
	exit(EXIT_FAILURE);
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

static void __cleanup__(const int _fd, t_shell *_shell, enum e_cleanup_option opt)
{
	static int fd;
	static t_shell *shell;

	if (opt == asg)
	{
		fd = _fd;
		shell = _shell;
	}
	else
	{
		close(fd);
		__t_shell__(shell);
	}
}

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted)
{
	t_fd	fd;
	char	*line;

	if (!eof || !shell)
		return (-1);
	fd = open_file(HEREDOC, O_CREAT | O_TRUNC | O_RDWR);
	set_signals_heredoc();
	__cleanup__(fd, shell, asg);
	rl_clear_history();
	line = readline(HEREDOC_PROMPT);
	while (line && !string_equal(line, eof))
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
	__cleanup__(fd, shell, delete);
	return (get_exit_status());
}
