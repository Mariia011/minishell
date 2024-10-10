/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast_skeleton.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:25:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:00:16 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		insert_redirections(t_listnode *first, t_listnode *second,
					t_ast *ast, t_shell *shell);

static t_ast	*boba(t_list *tokens, t_shell *shell, t_ast *ast);

t_ast	*make_ast_skeleton(t_list *tokens, t_shell *shell)
{
	t_ast		*ast;
	t_listnode	*op;
	t_listnode	*pair;

	ast = make_ast_empty(shell);
	op = shrfind_if(tokens->head, tokens->tail, is_binary_operator, shell);
	if (!op)
		return (boba(tokens, shell, ast));
	else
		pair = shrfind_if(tokens->head, op->prev, is_binary_operator, shell);
	insert_redirections(op, tokens->tail, ast, shell);
	while (op)
	{
		if (!pair)
			pair = tokens->head;
		insert_ast_node(ast, make_op_node(op));
		insert_redirections(pair, op, ast, shell);
		if (pair != tokens->head)
			insert_ast_node(ast, make_op_node(pair));
		op = shrfind_if(tokens->head, pair->prev, is_binary_operator, shell);
		if (op)
			pair = shrfind_if(tokens->head, op->prev, is_binary_operator,
					shell);
	}
	return (ast);
}

static t_ast	*boba(t_list *tokens, t_shell *shell, t_ast *ast)
{
	insert_redirections(tokens->head, tokens->tail, ast, shell);
	return (ast);
}

static void	insert_redirections(t_listnode *first, t_listnode *second,
		t_ast *ast, t_shell *shell)
{
	t_listnode	*r;

	r = shfind_if(first, second, is_redirection_token, shell);
	while (r)
	{
		insert_ast_node(ast, make_op_node(r));
		r = shfind_if(r->next, second, is_redirection_token, shell);
	}
}
