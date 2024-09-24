/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 15:54:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*make_shell(char **env)
{
	t_shell	*shell;

	shell = __malloc(sizeof(t_shell));
	shell->env = make_tree_from_matrix(env, string_less);
	shell->export = make_export(shell);
	shell->history = make_list();
	shell->quoted_tokens = make_set();
	shell->stddesc = make_stddesc();
	make_shlvl(shell);
	export_update(shell, "SHELL", "minishell");
	export_update(shell, "OLDPWD", "");
	unset_var(shell, "_");
	export_update(shell, "__HOME_CACHE__", get_val(shell->export, "HOME"));

	shell->logfile = make_logfile(shell);

	char *username __attribute__((cleanup(__delete_string))) = __strdup(get_val(shell->export, "USER"));

	username = (username) ? __strappend(username, "@", NULL) : __make_string_empty();

	shell->prompt = __make_string("\033[0;35m\e[3m", username, "minishell\033[0;32m\e[3m>$ \033[0m", NULL);

	return (shell);
}
