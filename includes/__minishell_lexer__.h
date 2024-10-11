/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_lexer__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:47:09 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/11 10:44:52 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_LEXER___H
# define __MINISHELL_LEXER___H

# include "minishell.h"

// wildcards
bool	is_wildcard(t_listnode *node);
bool	is_not_wildcard(t_listnode *node);

bool	is_wildcard_token(t_listnode *node, t_shell *shell);

// syntax
bool	is_pipe_token(t_listnode *node, t_shell *shell);
bool	is_and_token(t_listnode *node, t_shell *shell);
bool	is_or_node_token(t_listnode *node, t_shell *shell);
bool	is_special_symbol(t_listnode *node, t_shell *shell);
bool	not_special_symbol(t_listnode *node, t_shell *shell);
bool	is_binary_operator(t_listnode *node, t_shell *shell);
bool	not_binary_operator(t_listnode *node, t_shell *shell);
bool	not_binary_operator_nor_parenthesis(t_listnode *node, t_shell *shell);
bool	is_and(char *val);
bool	is_or(char *val);
bool	is_pipe(char *val);

bool	is_space_token(t_listnode *token, t_shell *shell);
bool	is_quote(char *s);
bool	is_single_redirection(char *val);
bool	is_redirection(const char *val);
bool	is_name(char *s);
bool	is_alpha(const char c);
bool	is_digit(const char c);
bool	is_name_part(const char c);
bool	not_name_part(char c);
bool				is_redirection_token(t_listnode *node, t_shell *shell);
bool				is_quote_node(t_listnode *const node);
bool				is_invokable(t_cmd *cmd);
bool				is_program(t_cmd *cmd);
bool				is_parenthesis_token(t_listnode *token, t_shell *shell);
bool				not_parenthesis_token(t_listnode *token, t_shell *shell);
bool				is_closing_parenthesis(char *text);
bool				is_opening_parenthesis(char *text);
bool				is_opening_parenthesis_token(t_listnode *token,
						t_shell *shell);
bool				is_closing_parenthesis_token(t_listnode *token,
						t_shell *shell);
bool				is_parenthesis(char *text);

// parsing
t_list	*tokenize(char *raw_cmd) __attribute__((warn_unused_result));
t_list	*preprocess(t_list *tokens,
			t_shell *shell) __attribute__((warn_unused_result));
void	dollar_sign_resolver(t_list *tokens, t_shell *shell);
int		redirection_resolver(t_list *tokens, t_cmd *cmd);
int		sort_tokens(t_cmd *cmd, t_list *tokens);
void	merge_tokens(t_shell *shell, t_list *tokens);
void	merge_redirections(t_list *tokens);

void	merge_inside_quotes(t_list *tokens);
void	merge_inside_quotes_the_good_part(t_list *tokens, t_listnode **t,
				t_listnode **next);

#endif // __MINISHELL_LEXER___H
