/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_ast__.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 16:40:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHEL_AST___H
#define __MINISHEL_AST___H

#include "cocobolo.h"
#include "minishell.h"

typedef s_ast t_ast;
typedef s_ast_node t_ast_node;
typedef enum e_ast_node_type t_ast_node_type;
typedef enum s_ast_cmd_node 	t_ast_cmd_node;
typedef enum s_ast_filetype_node t_ast_filetype_node;

enum e_ast_node_type
{
	OR,
	AND,
	PIPE,
	REDIRECTION,
	CMD
};

struct s_ast
{
	t_node *root;
	t_shell *shell;
};

struct s_ast_node
{
	t_ast_node_type type;
	t_node 			*right;
	t_node 			*left;
	t_node 			*root;
};

struct s_ast_cmd_node
{
	t_ast_node_type type;
	t_cmd			*cmd_ptr;
	t_node 			*right;
	t_node 			*left;
	t_node 			*root;
};

struct s_ast_filetype_node
{
	t_ast_node_type type;
	t_fd			fd;
	char			*filename;
	t_node 			*right;
	t_node 			*left;
	t_node 			*root;
};

#endif //__MINISHEL_AST___H
