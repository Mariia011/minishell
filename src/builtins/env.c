/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:15:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:04:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__print_env__(t_tree_node *node);

void	env(t_cmd *cmd)
{
	int		status;
	char	*str;

	if (!cmd || !cmd->shell)
		return ;
	status = 0;
	if (invalid_option(cmd) == -1)
		status = 1;
	else if (!empty(cmd->args))
	{
		str = __make_string("env", ": ", front(cmd->args)->val,
				": No such file or directory", NULL);
		__perror(str);
		__delete_string(&str);
		status = 127;
	}
	else
		print_tree_inorder_custom(cmd->shell->env, __print_env__);
	set_exit_status(status);
}

void	__print_env__(t_tree_node *node)
{
	if (!node)
		return ;
	printf("%s=", node->key);
	if (node->val)
		printf("%s", node->val);
	printf("\n");
}
