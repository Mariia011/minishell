/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_vol_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:04:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 20:05:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	substitute_args(t_listnode *wildcard_node, t_list *args,
		t_list *survived)
{
	t_listnode	*w_node;

	w_node = survived->tail;
	while (w_node)
	{
		list_insert(args, wildcard_node, w_node->val);
		w_node = w_node->prev;
	}
}

char	*contains_it(char *dirname, char *req)
{
	char	*guess;

	guess = __strstr(dirname, req);
	if (guess)
		return (guess + __strlen(req));
	return (NULL);
}

char	*starts_with(char *dirname, char *req)
{
	if (__str_starts_with(dirname, req))
		return (dirname + __strlen(req));
	return (NULL);
}

char	*ends_with(char *dirname, char *req)
{
	if (__str_ends_with(dirname, req))
		return (dirname + __strlen(dirname) - 1);
	return (NULL);
}
