/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/10 15:25:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtin_lookup(t_command *cmd);
static int	replace_cmd_name(t_command *cmd, t_node *node);

int	cmd_lookup(t_command *cmd)
{
	t_list *path	__attribute__((cleanup(list_clear)));

	path = NULL;
	if (!cmd)
		return (-1);
	if (builtin_lookup(cmd) == 0)
		return (0);
	path = get_path(cmd->shell);
	if (!string_equal(cmd->name, ""))
	{
		if (__strchr(cmd->name, '/') == false)
		{
			if (find_range(path, cmd->name, __cmd_exists__))
				return (replace_cmd_name(cmd, find_range(path,
							cmd->name, __cmd_exists__)));
		}
		else
			return absolute_path_lookup(cmd);
	}
	__va_perror(cmd->name, ": command not found", NULL);
	set_exit_status(127);
	return (-1);
}

int	set_eval_to_prog_i_love_norminette(t_command *cmd)
{
	cmd->eval = eval_prog;
	return (0);
}

static int	replace_cmd_name(t_command *cmd, t_node *node)
{
	char	*resolved_name;

	resolved_name = __make_string(node->val, "/", cmd->name, NULL);
	free(cmd->name);
	cmd->name = resolved_name;
	cmd->eval = eval_prog;
	return (0);
}

bool	__cmd_exists__(const char *path, const char *name)
{
	char *guess	__attribute__((cleanup(__delete_string)));

	guess = __make_string(path, "/", name, NULL);
	return (0 == access(guess, F_OK));
}

static int	builtin_lookup(t_command *cmd)
{
	if (string_equal(cmd->name, "pwd"))
		cmd->eval = pwd;
	else if (string_equal(cmd->name, "history"))
		cmd->eval = history;
	else if (string_equal(cmd->name, "export"))
		cmd->eval = export;
	else if (string_equal(cmd->name, "echo"))
		cmd->eval = echo;
	else if (string_equal(cmd->name, "unset"))
		cmd->eval = unset;
	else if (string_equal(cmd->name, "env"))
		cmd->eval = env;
	else if (string_equal(cmd->name, "cd"))
		cmd->eval = cd;
	else if (string_equal(cmd->name, "exit"))
		cmd->eval = msh_exit;
	if (cmd->eval == NULL)
		return (-1);
	return (0);
}
