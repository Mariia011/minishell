/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_commands__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 19:04:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_COMMANDS___H
# define __MINISHELL_COMMANDS___H

# include "__minishell_typedefs__.h"
# include "minishell.h"
# include <cocobolo.h>

struct				s_cmd
{
	t_shell *shell;
	char *name;
	char *orig_name;
	t_list *options;
	t_list *args;		//here was an attribute deprecated

	t_eval eval;
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

t_cmd			*make_command(char *raw_cmd, t_shell *shell)
					__attribute__((warn_unused_result));
t_cmd_container		*make_cmd_container(char *raw_cmd,
						t_shell *shell) __attribute__((warn_unused_result));
void				__t_command__(t_cmd *cmd);
void				__t_cmd_container__(t_cmd_container **cmdsptr);

#endif // __MINISHELL_COMMANDS___H
