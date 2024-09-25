/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:19:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/25 01:20:00 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_ast *bear_a_tree()
// {
//     __malloc(sizeof(t_ast)); //ask why not calloc
//     root = NULL;
    
// }

void	build_ast(t_list *tokens, t_shell *shell)
{
    t_ast *the_tree = __malloc(sizeof(t_ast));
    t_node *node = shrfind_if(tokens->head, tokens->last, keyword_parse, shell);
    
    while(node)
    {
        if(!the_tree->root)
            the_tree->root = node;
        else
        {
           while(the_tree->root->left != NULL)
            {
                the_tree->root->left = node;
            }
        tree->root->left = cur_node;
        }

        node = shrfind_if(node, tokens->last, is_special_symbol, shell);
                
    }
}
