/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 10:43:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and $variables
t_list	*preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell)
		return (NULL);
	dollar_sign_resolver(tokens, shell);
	merge_tokens(shell, tokens);
	remove_spaces(shell, tokens);
	recover_variables(tokens, shell);
	if (!syntax_analysis(tokens, shell))
	{
		set_exit_status_no_of(258);
		list_clear(&tokens);
	}
	if (count_range(tokens, "<<") > HEREDOC_MAX)
	{
		list_clear(&tokens);
		__t_shell__(shell);
		__perror("maximum here-document count exceeded");
		exit(2);
	}
	return (tokens);
}
