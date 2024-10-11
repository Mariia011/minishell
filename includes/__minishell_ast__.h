/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_ast__.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 10:41:36 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_AST___H
# define __MINISHELL_AST___H

# include "cocobolo.h"
# include "minishell.h"

typedef struct s_ast			t_ast;
typedef struct s_ast_node		t_ast_node;
typedef enum e_ast_node_type	t_ast_node_type;
typedef enum e_redirection_type	t_redirection_type;
typedef struct s_fd_auth		t_fd_auth;
typedef struct s_authorized_fds	t_authorized_fds;

enum							e_ast_node_type
{
	OR,
	AND,
	PIPE,
	REDIRECTION,
	FILENODE,
	CMD
};

enum							e_redirection_type
{
	in = 0,
	out = 1,
	redirect_in = 2,
	redirect_out = 4,
	redirect_heredoc = 8,
	redirect_append = 16,
	invalid_redirection = 256
};

struct							s_fd_auth
{
	t_fd						fd;
	t_ast_node					*author;
};

struct							s_authorized_fds
{
	t_fd_auth					stdin;
	t_fd_auth					stdout;
};

struct							s_ast
{
	t_ast_node					*root;
	t_shell						*shell;
	t_ast_node					*last_process_cmd;
	t_ast_node					*last_cmd;
};

struct							s_ast_node
{
	t_ast_node_type				type;

	t_cmd						*cmd_ptr;
	t_ast						*ast;
	t_fd						fd;
	char						*filename;
	t_redirection_type			redirection_type;

	t_listnode					*orig_token;

	t_ast_node					*right;
	t_ast_node					*left;
	t_ast_node					*p;
};

t_ast							*make_ast_empty(t_shell *shell)
								__attribute__((warn_unused_result));
t_ast_node_type					node_gettype(t_listnode *token);
t_ast_node						*make_op_node(t_listnode *token);
void							insert_ast_node(t_ast *ast, t_ast_node *z);
t_ast							*make_ast_skeleton(t_list *tokens,
									t_shell *shell);
t_ast_node						*make_file_node(t_listnode *token);
t_ast_node						*make_cmd_node(t_cmd *cmd);
void							insert_cmd_node(t_ast *ast, t_ast_node *z);
t_ast							*make_ast(char *line, t_shell *shell);
t_ast_node						*find_last_process_cmd(t_ast_node *root);
t_ast_node						*find_last_cmd(t_ast *ast);
t_ast_node						*ast_find_by_token(t_ast *ast,
									t_listnode *token);
void							ast_balance(t_ast *ast, t_list *tokens);

void							ast_eval(t_ast *ast);

void							ast_lrotate(t_ast *ast, t_ast_node *x,
									t_ast_node *z);
void							ast_rrotate(t_ast *ast, t_ast_node *x,
									t_ast_node *z);

void							ast_node_clear(t_ast_node *node);
void							ast_clear(t_ast **astptr);

void							deduce_redirection_type(t_ast_node *node);

#endif //__MINISHELL_AST___H
