/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_commands__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:42:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_COMMANDS___H
# define __MINISHELL_COMMANDS___H

# include "__minishell_typedefs__.h"
# include "minishell.h"
# include <cocobolo.h>

# define NOT_FOUND 127

struct		s_cmd
{
	t_shell	*shell;
	char	*name;
	char	*orig_name;
	t_list	*options;
	t_list	*args;

	int		exit_status;

	char	*err;
	bool	invokable;
	bool	forkable;

	t_eval	eval;
	t_eval	eval_core;

	t_list	*tokens;

	int		redirection;
	pid_t	pid;
};

t_cmd		*make_command(t_list *tokens,
				t_shell *shell) __attribute__((warn_unused_result));
void		__t_cmd__(t_cmd *cmd);

void		cmd_runtime_init(t_cmd *cmd);

#endif // __MINISHELL_COMMANDS___H
