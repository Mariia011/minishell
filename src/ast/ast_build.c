/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:19:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/25 19:42:03 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node_type ast_node_type(t_node *token)
{
	if (is_or(token->val))
		return (OR);
	else if (is_and(token->val))
		return (AND);
	else if (is_pipe(token->val))
		return (PIPE);
	else if (is_redirection(token->val))
		return (REDIRECTION);
	else
		return (CMD);
}

void	build_ast(t_list *tokens, t_shell *shell)
{
    t_ast *the_tree = __malloc(sizeof(t_ast));
	the_tree->root = NULL;
	the_tree->root = NULL;
	the_tree->shell = shell;
	the_tree->last_process_cmd = NULL;
    t_node *node = shrfind_if(tokens->head, tokens->tail, is_special_symbol, shell);

    while(node)
    {
		insert_ast_node(the_tree, make_op_node(ast_node_type(node)));

        node = shrfind_if(tokens->head, node->prev, is_special_symbol, shell);

    }
}
