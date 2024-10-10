/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:02:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:08:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dfs(t_ast_node *root);

void	ast_clear(t_ast **astptr)
{
	t_ast	*ast;

	if (NULL == astptr || NULL == *astptr)
		return ;
	ast = *astptr;
	dfs(ast->root);
	ast->root = NULL;
	ast->shell->ast = NULL;
	ast->shell = NULL;
	ast->last_cmd = NULL;
	ast->last_process_cmd = NULL;
	free(ast);
	*astptr = NULL;
}

void	dfs(t_ast_node *root)
{
	if (!root)
		return ;
	dfs(root->left);
	dfs(root->right);
	ast_node_clear(root);
}
