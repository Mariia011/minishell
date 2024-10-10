/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_vol_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/06 14:44:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		wildcard_resolve_core(t_list *tokens, t_listnode **wild,
					t_list *dir, t_list *reqs);

t_list	*get_cwd_files(void)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*res;
	t_matrix		tmp;

	res = make_list();
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	dp = readdir(dir);
	while (dp != NULL)
	{
		push_back(res, dp->d_name);
		dp = readdir(dir);
	}
	closedir(dir);
	tmp = make_matrix_from_list(res);
	matrix_sort(tmp, string_less);
	list_clear(&res);
	res = make_list_from_matrix(tmp);
	matrix_clear(&tmp);
	return (res);
}

static bool	check_node(char *dirname, t_list *reqs)
{
	t_listnode		*cur;
	char			*dir_p;
	wildcard_fptr	fptr;

	cur = reqs->head;
	dir_p = dirname;
	fptr = contains_it;
	while (cur)
	{
		if (!string_equal(cur->val, "*"))
		{
			if (cur == reqs->head)
				fptr = starts_with;
			else if (cur == reqs->tail)
				fptr = ends_with;
			else
				fptr = contains_it;
			dirname = fptr(dirname, cur->val);
			if (!dirname)
				return (false);
		}
		cur = cur->next;
	}
	return (true);
}

static t_list	*check_all_dirs(t_list *dir, t_list *reqs)
{
	t_list		*res;
	t_list		*dir_cpy;
	t_listnode	*dir_node;

	res = make_list();
	if (empty(dir))
		return (res);
	dir_cpy = make_list_copy_range(dir, NULL);
	if (!__str_starts_with(reqs->head->val, "."))
		list_remove_if(dir_cpy, ".", __str_starts_with);
	dir_node = dir_cpy->head;
	while (dir_node)
	{
		if (check_node(dir_node->val, reqs))
			push_back(res, dir_node->val);
		dir_node = dir_node->next;
	}
	list_clear(&dir_cpy);
	return (res);
}

void	wildcard_resolve(t_list *tokens, t_shell *shell)
{
	t_list		*dir;
	int			i;
	t_listnode	*wild;
	t_list		*reqs;
	t_listnode	*save;

	dir = get_cwd_files();
	i = 0;
	wild = tokens->head;
	reqs = NULL;
	wild = find_if(tokens->head, tokens->tail, is_wildcard);
	while (wild)
	{
		save = wild->next;
		if (!find_addr(shell->quoted_tokens, wild)
			&& (wild != tokens->head && !string_equal(wild->prev->val, "<<")))
		{
			wildcard_resolve_core(tokens, &wild, dir, reqs);
		}
		wild = save;
		wild = find_if(wild, tokens->tail, is_wildcard);
	}
	list_clear(&dir);
}

static void	wildcard_resolve_core(t_list *tokens, t_listnode **wild,
		t_list *dir, t_list *reqs)
{
	t_list	*survived;

	reqs = make_list_from_string((*wild)->val, "*", all);
	survived = check_all_dirs(dir, reqs);
	if (!empty(survived))
	{
		substitute_args((*wild), tokens, survived);
	}
	pop(tokens, (*wild));
	list_clear(&survived);
	list_clear(&reqs);
}
