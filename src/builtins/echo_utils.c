/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:01:36 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	echo_arglist(t_list *arglist)
{
	t_listnode	*arg;

	if (!arglist)
		return ;
	arg = front(arglist);
	while (arg)
	{
		printf("%s", arg->val);
		if (arg->next)
			printf(" ");
		arg = arg->next;
	}
}

bool	last_nl(t_listnode *const node)
{
	if (!node || !node->val)
		return (false);
	return (is_n(node->val) && (node->next == NULL || !is_n(node->next->val)));
}

bool	not_n_predicate(char c)
{
	return (c != 'n');
}

bool	is_n(char *opt)
{
	if (__strlen(opt) < 2)
		return (false);
	opt++;
	return (*__strchr_p(opt, not_n_predicate) == '\0');
}

#pragma GCC diagnostic pop
