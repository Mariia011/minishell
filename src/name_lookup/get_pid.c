/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:45:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/04 20:55:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PS_ ".__ps__.txt"

static void	exec_ps(t_shell *shell);
static char	*get_pid_core(t_fd fd, t_shell *shell);

char	*get_pid(t_shell *shell)
{
	char		*val;
	t_optional	p;
	int			fd;

	exec_ps(shell);
	fd = open_file(PS_, O_WRONLY | O_APPEND);
	__putstr_fd("__EOF__", fd);
	close(fd);
	fd = open_file(PS_, O_RDONLY);
	val = get_pid_core(fd, shell);
	p = __atoi(val);
	free(val);
	val = __itoa(value(&p));
	close(fd);
	unlink(PS_);
	return (val);
}

static char	*get_pid_core(t_fd fd, t_shell *shell)
{
	t_list		*list;
	t_listnode	*node;
	char		*val;

	val = get_next_line(fd);
	list = make_list();
	while (val && !__strstr(val, "__EOF__"))
	{
		push_back(list, val);
		free(val);
		val = get_next_line(fd);
	}
	free(val);
	get_next_line(-1);
	node = list->tail;
	while (node && !__strstr(node->val, "minishell"))
		node = node->prev;
	if (!node || !node->val)
		val = __strdup("1337");
	else
		val = __strdup(node->val);
	list_clear(&list);
	return (val);
}

static void	exec_ps(t_shell *shell)
{
	t_fd		pid;
	t_matrix	t_env;
	char		*cmd[2];
	t_fd		fd;

	cmd[0] = "/bin/ps";
	cmd[1] = NULL;
	t_env = NULL;
	pid = __fork();
	if (pid == 0)
	{
		fd = open_file(PS_, O_WRONLY | O_CREAT | O_TRUNC);
		t_env = make_matrix_from_tree(shell->env);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(cmd[0], cmd, t_env);
		__t_shell__(shell);
		matrix_clear(&t_env);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	matrix_clear(&t_env);
}
