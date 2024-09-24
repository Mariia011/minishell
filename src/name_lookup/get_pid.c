/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:45:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/24 01:21:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PS_ ".__ps__.txt"

static void	exec_ps(t_shell *shell);

char	*get_pid(t_shell *shell)
{
	char		*val;
	t_optional	p;

	val = NULL;
	exec_ps(shell);
	int fd = open_file(PS_, O_WRONLY | O_APPEND);
	__putstr_fd("__EOF__", fd);
	close(fd);
	fd = open_file(PS_, O_RDONLY);
	t_list *list = make_list();
	val = get_next_line(fd);
	while (val && !__strstr(val, "__EOF__"))
	{
		push_back(list, val);
		free(val);
		val = get_next_line(fd);
	}

	free(val);
	get_next_line(-1);

	t_node *node = list->tail;

	while (node && !__strstr(node->val, "minishell"))
		node = node->prev;

	if (!node || !node->val)
		val = __strdup("1337");

	else
		val = __strdup(node->val);

	p = __atoi(val);
	free(val);
	val = __itoa(value(&p));
	close(fd);
	unlink(PS_);
	list_clear(&list);
	return (val);
}

static void	exec_ps(t_shell *shell)
{
	t_fd		pid;
	t_matrix	t_env;
	char		*cmd[2];

	cmd[0] = "/bin/ps";
	cmd[1] = NULL;
	t_env = NULL;
	pid = __fork();
	if (pid == 0)
	{
		t_fd fd = open_file(PS_,  O_WRONLY | O_CREAT | O_TRUNC);
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
