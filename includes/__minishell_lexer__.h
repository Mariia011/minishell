/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_lexer__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:47:09 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/25 00:47:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_LEXER___H
# define __MINISHELL_LEXER___H

# include "minishell.h"

// wildcards
bool is_wildcard(t_node *node);
bool is_not_wildcard(t_node *node);

// syntax
bool is_pipe_node(t_node *node, t_shell *shell);
bool is_and_node(t_node *node, t_shell *shell);
bool is_or_node(t_node *node, t_shell *shell);
bool is_special_symbol(t_node * node, t_shell *shell);
bool not_special_symbol(t_node * node, t_shell *shell);
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
