/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_process_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:18:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 02:29:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_ast_node	*find_last_process_cmd(t_ast_node *root)
{
	if (!root) return NULL;

	t_ast_node	*curr = NULL;
	t_ast_node	*l = NULL;
	t_ast_node	*r = NULL;

	if ((root->type == CMD && is_program(root->cmd_ptr)))
		curr = root;

	r = find_last_process_cmd(root->right);

	if (r) return r;

	if (curr) return curr;

	l = find_last_process_cmd(root->left);

	return l;
}
