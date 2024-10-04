/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_process_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:11:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:11:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*find_last_process_cmd(t_ast_node *root)
{
	t_ast_node	*curr;
	t_ast_node	*l;
	t_ast_node	*r;

	if (!root)
		return (NULL);
	curr = NULL;
	l = NULL;
	r = NULL;
	if ((root->type == CMD && is_program(root->cmd_ptr)))
		curr = root;
	r = find_last_process_cmd(root->right);
	if (r)
		return (r);
	if (curr)
		return (curr);
	l = find_last_process_cmd(root->left);
	return (l);
}
