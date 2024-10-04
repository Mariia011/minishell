/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ast_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:50:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:10:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_ast_node(t_ast *ast, t_ast_node *z)
{
	t_ast_node	*x;

	x = ast->root;
	while (x && x->left)
		x = x->left;
	if (x == NULL)
		ast->root = z;
	else
	{
		x->left = z;
		z->p = x;
	}
	if (z->type == REDIRECTION)
		z->right = make_file_node(z->orig_token->next);
}
