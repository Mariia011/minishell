/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:39:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:10:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_balance(t_ast *ast, t_list *tokens)
{
	t_listnode	*p;
	t_listnode	*n;
	t_ast_node	*x;
	t_ast_node	*z;

	p = shfind_if(tokens->head, tokens->tail, is_opening_parenthesis_token,
			ast->shell);
	if (!p)
		return ;
	while (p)
	{
		n = shrfind_if(p->next, shrfind_if(p->next, tokens->tail,
					is_closing_parenthesis_token, ast->shell),
				is_special_symbol, ast->shell);
		x = ast_find_by_token(ast, n);
		z = ast_find_by_token(ast, shrfind_if(tokens->head, p->prev,
					is_special_symbol, ast->shell));
		ast_rrotate(ast, x, z);
		p = shfind_if(p->next, tokens->tail, is_opening_parenthesis_token,
				ast->shell);
	}
}
