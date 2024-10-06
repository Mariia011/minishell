/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_op_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:36:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/07 00:53:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*make_op_node(t_listnode *token)
{
	t_ast_node	*res;

	res = __malloc(sizeof(t_ast_node));
	res->type = node_gettype(token);
	res->cmd_ptr = NULL;
	res->fd = -1;
	res->ast = NULL;
	res->filename = NULL;
	res->left = NULL;
	res->right = NULL;
	res->p = NULL;
	res->redirection_type = 0;
	res->orig_token = token;
	deduce_redirection_type(res);
	return (res);
}

void	deduce_redirection_type(t_ast_node *node)
{
	if (node->type == REDIRECTION)
	{
		if (string_equal(node->orig_token->val, "<"))
			node->redirection_type |= redirect_in;
		else if (string_equal(node->orig_token->val, "<<"))
			node->redirection_type |= redirect_heredoc;
		else if (string_equal(node->orig_token->val, ">"))
			node->redirection_type |= redirect_out;
		else if (string_equal(node->orig_token->val, ">>"))
			node->redirection_type = redirect_append;
	}
	else
		node->redirection_type = invalid_redirection;
}
