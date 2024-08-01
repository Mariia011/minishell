/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 23:13:25 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens);

	merge_tokens(tokens);

	// print_list(tokens);
	// return NULL;

	list_remove(tokens, " ");
	list_remove(tokens, "\'");
	list_remove(tokens, "\"");


	return tokens;
}
