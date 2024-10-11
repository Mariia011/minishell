/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:29:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 15:09:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	make_cmd_arr_core(t_list *tokens, t_shell *shell, t_cmd **res);

t_cmd	**make_cmd_arr(t_list *tokens, t_shell *shell)
{
	size_t	size;
	t_cmd	**res;

	if (empty(tokens) || !shell)
		return (NULL);
	size = shcount_if(tokens->head, tokens->tail,
			is_binary_operator, shell) + 2;
	res = __calloc(sizeof(t_cmd *) * size);
	res[size - 1] = NULL;
	make_cmd_arr_core(tokens, shell, res);
	return (res);
}

static void	make_cmd_arr_core(t_list *tokens, t_shell *shell, t_cmd **res)
{
	size_t		i;
	t_listnode	*first;
	t_listnode	*second;
	t_list		*partition;

	i = 0;
	first = tokens->head;
	while (first)
	{
		second = shfind_if(first, tokens->tail, is_binary_operator, shell);
		if (!second)
			second = tokens->tail;
		else
			second = second->prev;
		partition = make_partition(shell, first, second);
		shremove_if(partition, is_parenthesis_token, shell);
		pop_redirections(partition, shell);
		res[i++] = make_command(partition, shell);
		if (second == tokens->tail)
			first = second->next;
		else
			first = second->next->next;
	}
}

t_list	*make_partition(t_shell *shell, t_listnode *first, t_listnode *last)
{
	t_list		*list;
	t_listnode	*curr;

	if (!shell || !first || !last)
		return (NULL);
	list = make_list();
	curr = first;
	while (curr && curr->prev != last)
	{
		push_back(list, curr->val);
		if (find_addr(shell->quoted_tokens, curr))
		{
			save_token(shell->quoted_tokens, back(list));
		}
		curr = curr->next;
	}
	return (list);
}
