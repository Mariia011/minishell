/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:39:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ast_balance(t_ast *ast, t_list *tokens) // echo a && (echo d || (echo b && echo c))
{
	t_listnode *p = shfind_if(tokens->head, tokens->tail, is_opening_parenthesis_token, ast->shell);

	if (!p) return;

	while (p)
	{
		t_listnode	   *n = shrfind_if(p->next, shrfind_if(p->next, tokens->tail, is_closing_parenthesis_token, ast->shell), is_special_symbol, ast->shell);
		t_ast_node *x = ast_find_by_token(ast, n);
		t_ast_node *z = ast_find_by_token(ast, shrfind_if(tokens->head, p->prev, is_special_symbol, ast->shell));

		ast_rrotate(ast, x, z);
		p = shfind_if(p->next, tokens->tail, is_opening_parenthesis_token, ast->shell);
	}

}
