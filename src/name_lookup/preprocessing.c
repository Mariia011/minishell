/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 20:13:30 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and $variables
t_list *preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens, shell);

	merge_tokens(tokens);

	list_remove(tokens, " ");

	return tokens;
}
