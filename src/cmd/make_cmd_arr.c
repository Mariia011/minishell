/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:29:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/06 14:50:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**make_cmd_arr(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	size_t size = shcount_if(tokens->head, tokens->tail, is_special_symbol, shell) + 2;
	size_t i = 0;
	t_cmd **res = __calloc(sizeof(t_cmd *) * size);

	res[size - 1] = NULL;

	t_listnode *first = tokens->head;

	while (first)
	{
		t_listnode *second = shfind_if(first, tokens->tail, is_binary_operator, shell);

		if (!second)
			second = tokens->tail;
		else
			second = second->prev;

		t_list *partition = make_partition(shell, first, second);

		shremove_if(partition, is_parenthesis_token, shell);
		pop_redirections(partition, shell);

		res[i++] = make_command(partition, shell);

		if (second == tokens->tail)
			first = second->next;
		else
			first = second->next->next;
	}
	return res;
}

t_list	*make_partition(t_shell *shell, t_listnode *first, t_listnode *last)
{
	t_list	*list;
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
