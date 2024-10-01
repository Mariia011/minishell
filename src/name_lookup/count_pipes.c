/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:09:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t __count_pipes__(t_listnode *token, t_shell *shell)
{
	if (!token) return 0;

	return (!is_quoted_token(shell->quoted_tokens, token) && string_equal(token->val, "|")) + __count_pipes__(token->next, shell);
}

size_t count_pipes(t_list *tokens, t_shell *shell)
{
	if (!tokens || !shell) return 0;

	return __count_pipes__(tokens->head, shell);
}
