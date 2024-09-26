/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_ast__.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/26 20:30:10 by aamirkha         ###   ########.fr       */
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
	FILENODE,
	CMD
};

struct s_ast
{
	t_ast_node 	*root;
	t_shell 	*shell;
	t_ast_node 	*last_process_cmd;
	t_ast_node	*last_cmd;
};

struct s_ast_node
{
	t_ast_node_type			type;

	t_cmd					*cmd_ptr;
	t_fd					fd;
	char					*filename;

	t_node				*orig_token;

	t_ast_node 			*right;
	t_ast_node 			*left;
	t_ast_node 			*p;
};


t_ast			*make_ast_empty(t_shell *shell) __attribute__((warn_unused_result));
t_ast_node_type	node_gettype(t_node *token);
t_ast_node		*make_op_node(t_node *token);
void			insert_ast_node(t_ast *ast, t_ast_node *z);
t_ast			*make_ast_skeleton(t_list *tokens, t_shell *shell);
t_ast_node		*make_cmd_node(t_cmd *cmd);
void			insert_cmd_node(t_ast *ast, t_ast_node *z);
t_ast			*make_ast(char *line, t_shell *shell);
t_ast_node		*find_last_process_cmd(t_ast_node *root);
t_ast_node		*find_last_cmd(t_ast *ast);
t_ast_node		*ast_find_by_token(t_ast * ast, t_node *token);
void			ast_balance(t_ast *ast, t_list *tokens);

void 			ast_eval(t_ast *ast);

void			ast_lrotate(t_ast *ast, t_ast_node *x, t_ast_node *z);
void			ast_rrotate(t_ast *ast, t_ast_node *x, t_ast_node *z);


#endif //__MINISHEL_AST___H
