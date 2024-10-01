/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtin_lookup(t_cmd *cmd);
static int	replace_cmd_name(t_cmd *cmd, t_listnode *node);

int	cmd_lookup(t_cmd *cmd)
{
	t_list *path	__attribute__((cleanup(list_clear)));

	path = NULL;
	if (!cmd)
		return (-1);
	if (builtin_lookup(cmd) == 0)
	{
		cmd->eval = builtin_preeval;
		return (0);
	}
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
		{
			if (absolute_path_lookup(cmd) == -1)
			{
				cmd->eval = errcmd;
				return -1;
			}
			cmd->eval = eval_prog;
			return 0;
		}
	}
	cmd->err = __make_string(cmd->orig_name, ": command not found", NULL);
	cmd->exit_status = NOT_FOUND;
	cmd->eval = errcmd;
	return (-1);
}

int	set_eval_to_prog_i_love_norminette(t_cmd *cmd)
{
	cmd->eval = eval_prog;
	return (0);
}

static int	replace_cmd_name(t_cmd *cmd, t_listnode *node)
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

	struct stat buffer;

	stat(guess, &buffer);
	return (0 == access(guess, F_OK | X_OK) && !S_ISDIR(buffer.st_mode));
}

static int	builtin_lookup(t_cmd *cmd)
{
	if (string_equal(cmd->name, "pwd"))
		cmd->eval_core = pwd;
	else if (string_equal(cmd->name, "history"))
		cmd->eval_core = history;
	else if (string_equal(cmd->name, "export"))
		cmd->eval_core = export;
	else if (string_equal(cmd->name, "echo"))
		cmd->eval_core = echo;
	else if (string_equal(cmd->name, "unset"))
		cmd->eval_core = unset;
	else if (string_equal(cmd->name, "env"))
		cmd->eval_core = env;
	else if (string_equal(cmd->name, "cd"))
		cmd->eval_core = cd;
	else if (string_equal(cmd->name, "exit"))
		cmd->eval_core = msh_exit;
	if (cmd->eval_core == NULL)
		return (-1);
	return (0);
}
