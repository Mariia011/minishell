/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:15:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 18:58:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void dfs(t_ast_node *root);

int killall(t_ast *ast)
{
	dfs(ast->root);
	__perror("fork: Resource temporarily unavailable");
	return 1;
}

static void dfs(t_ast_node *root)
{
	if (!root)
		return;
	if (root->type == CMD && root->cmd_ptr->pid > -1)
	{
		kill(root->cmd_ptr->pid, SIGKILL);
		waitpid(root->cmd_ptr->pid, NULL, 0);
		root->cmd_ptr->pid = -1;
	}
}
