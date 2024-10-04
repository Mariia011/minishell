/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:32:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 17:17:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast *make_ast_empty(t_shell *shell)
{
	t_ast *res = __malloc(sizeof(t_ast));

	res->root = NULL;
	res->shell = shell;
	res->last_process_cmd = NULL;
	return res;
}
