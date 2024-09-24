/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:21:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/25 02:31:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast *make_ast(char *line, t_shell *shell)
{
	t_list	*tokens = preprocess(tokenize(line), shell);

	if (empty(tokens))
		return NULL;

	t_ast *ast = make_ast_skeleton(tokens, shell);

	t_cmd	**arr = make_cmd_arr(tokens, shell);

	int i = 0;
	while (arr[i]) i++;

	i--;

	while (i >= 0)
	{
		insert_cmd_node(ast, make_cmd_node(arr[i]));
		i--;
	}

	ast->last_process_cmd = find_last_process_cmd(ast);

	free(arr);
	list_clear(&tokens);
	return ast;
}
