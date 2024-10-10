/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_lexer__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:47:09 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/10 21:04:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_LEXER___H
# define __MINISHELL_LEXER___H

# include "minishell.h"

// wildcards
bool is_wildcard(t_listnode *node);
bool is_not_wildcard(t_listnode *node);

bool	is_wildcard_token(t_listnode *node, t_shell *shell);

// syntax
bool is_pipe_token(t_listnode *node, t_shell *shell);
bool is_and_token(t_listnode *node, t_shell *shell);
bool is_or_node_token(t_listnode *node, t_shell *shell);
bool is_special_symbol(t_listnode * node, t_shell *shell);
bool not_special_symbol(t_listnode * node, t_shell *shell);
bool is_binary_operator(t_listnode * node, t_shell *shell);
bool not_binary_operator(t_listnode * node, t_shell *shell);
bool not_binary_operator_nor_parenthesis(t_listnode * node, t_shell *shell);
bool is_and(char *val);
bool is_or(char *val);
bool is_pipe(char *val);



// parsing
t_list	*tokenize(char *raw_cmd) __attribute__((warn_unused_result));
t_list	*preprocess(t_list *tokens,
			t_shell *shell) __attribute__((warn_unused_result));
void	dollar_sign_resolver(t_list *tokens, t_shell *shell);
int		redirection_resolver(t_list *tokens, t_cmd *cmd);
int		sort_tokens(t_cmd *cmd, t_list *tokens);
void	merge_tokens(t_shell *shell, t_list *tokens);
void	merge_redirections(t_list *tokens);

#endif // __MINISHELL_LEXER___H
