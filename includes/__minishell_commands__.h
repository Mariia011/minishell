/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_commands__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/27 22:40:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_COMMANDS___H
# define __MINISHELL_COMMANDS___H

# include "__minishell_typedefs__.h"
# include "minishell.h"
# include <cocobolo.h>

#define NOT_FOUND 127

struct				s_cmd
{
	t_shell *shell;
	char *name;
	char *orig_name;
	t_list *options;
	t_list *args;		//here was an attribute deprecated

	int		exit_status;

	char	*err;
	bool 	invokable;
	bool 	forkable;

	t_eval eval;
	t_eval eval_core;

	t_list *tokens;

	int redirection;
	pid_t pid;
	// t_descriptor *descriptors;
};

struct				s_cmd_container
{
	t_shell			*shell;
	t_cmd		**arr;
	size_t			size;
	size_t			current_cmd_index;
	t_fd			*fds;
	t_list 		 	*tokens;
};

t_cmd				*make_command(t_list *tokens, t_shell *shell)
					__attribute__((warn_unused_result));
t_cmd_container		*make_cmd_container(char *raw_cmd,
						t_shell *shell) __attribute__((warn_unused_result));
void				__t_cmd__(t_cmd *cmd);
void				__t_cmd_container__(t_cmd_container **cmdsptr);

void				cmd_runtime_init(t_cmd *cmd);

#endif // __MINISHELL_COMMANDS___H
