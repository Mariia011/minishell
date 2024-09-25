/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_ast__.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 19:37:24 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHEL_AST___H
#define __MINISHEL_AST___H

#include "cocobolo.h"
#include "minishell.h"

typedef struct s_ast t_ast;
typedef struct s_ast_node t_ast_node;
typedef enum e_ast_node_type t_ast_node_type;

enum e_ast_node_type
{
	OR,
	AND,
	PIPE,
	REDIRECTION,
	CMD,
	FILENAME
};

struct s_ast
{
	t_ast_node 	*root;
	t_shell 	*shell;
	t_ast_node 	*last_process_cmd;
};

struct s_ast_node
{
	t_ast_node_type			type;
	t_cmd					*cmd_ptr;
	t_fd					fd;
	char					*filename;

	t_ast_node 			*right;
	t_ast_node 			*left;
	t_ast_node 			*p;
};

void insert_ast_node(t_ast *the_tree, t_ast_node *node);
void	build_ast(t_list *tokens, t_shell *shell);
t_ast_node *make_op_node(t_ast_node_type type);

#endif //__MINISHEL_AST___H
