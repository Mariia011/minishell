/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast_skeleton.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:25:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 18:33:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast *make_ast_skeleton(t_list *tokens, t_shell *shell)
{
	t_ast	*ast = make_ast_empty(shell);

	t_listnode *op = shrfind_if(tokens->head, tokens->tail, is_special_symbol, shell);

	while (op)
	{
		insert_ast_node(ast, make_op_node(op));
		op = shrfind_if(tokens->head, op->prev, is_special_symbol, shell);
	}

	return ast;
}
