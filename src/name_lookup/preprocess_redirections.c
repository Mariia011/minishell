/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:53:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 21:45:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	preprocess_redirections(t_list *tokens, t_cmd_container *container)
{
	t_node	*token;
	t_node	*next;

	token = tokens->head;
	while (token)
	{
		next = token->next;
		if (is_redirection(token->val))
		{
			if (preprocess_redirections_the_good_part(container, tokens, token) == -1)
				return (-1);
			next = token->next->next;
		}
		token = next;
	}
	get_next_fd_idx(NULL);
	return (0);
}

int	preprocess_redirections_the_good_part(t_cmd_container *container, t_list *tokens,
		t_node *token)
{
	if (!token->next || string_equal(token->next->val, ""))
	{
		if (token->next)
		{
			set_exit_status(1);
			__perror("ambiguous redirect");
		}
		else
			__perror("syntax error");
		set_exit_status_no_of(258);
		return (-1);
	}
	else if (-1 == redirect(token, container))
	{
		set_exit_status(1);
		return (-1);
	}
	return (0);
}
