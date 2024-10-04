/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:06:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 16:29:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node *make_file_node(t_listnode *token)
{
	t_ast_node *res = __malloc(sizeof(t_ast_node));
	res->type = FILENODE;
	res->cmd_ptr = NULL;
	res->fd = -1;
	res->filename = __strdup(token->val);
	res->left = NULL;
	res->right = NULL;
	res->p = NULL;
	res->orig_token = token;
	res->redirection_type = invalid_redirection;

	return (res);
}
