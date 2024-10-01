/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/01 15:31:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_cwd_files(void)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*res;

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

	t_matrix tmp __attribute__((cleanup(matrix_clear))) = make_matrix_from_list(res);

	matrix_sort(tmp, string_less);

	list_clear(&res);

	return (make_list_from_matrix(tmp));
}

char *contains_it(char *dirname, char *req)
{
	char *guess = __strstr(dirname, req);

	if (guess) return guess + __strlen(req);

	return NULL;
}

char *starts_with(char *dirname, char *req)
{
	if(__str_starts_with(dirname, req))
		return (dirname + __strlen(req));
	return (NULL);
}

char *ends_with(char *dirname, char *req)
{
	if(__str_ends_with(dirname, req))
		return (dirname + __strlen(dirname) - 1);
	return(NULL);
}


static bool check_node(char *dirname, t_list *reqs)
{
	char *(*fptr)(char *, char *);
	t_listnode *cur = reqs->head;
	char *dir_p = dirname;

	fptr = contains_it;
	while (cur)
	{
		if (string_equal(cur->val, "*"))
		{
			cur = cur->next;
			continue;
		}
		if(cur == reqs->head)
		{
			fptr = starts_with;
		}
		else if(cur == reqs->tail)
		{
			fptr = ends_with;
		}
		else
			fptr = contains_it;
		dirname = fptr(dirname, cur->val);
		if(!dirname)
			return false;
		cur = cur->next;
	}
	return true;
}

static t_list *check_all_dirs(t_list *dir, t_list *reqs)
{
	t_list *res = make_list();

	if (empty(dir))
		return (res);

	t_list *dir_cpy = make_list_copy_range(dir, NULL);

	if (!__str_starts_with(reqs->head->val, "."))
		list_remove_if(dir_cpy, ".", __str_starts_with);

	t_listnode *dir_node = dir_cpy->head;
	while(dir_node)
	{
		if (check_node(dir_node->val, reqs))
			push_back(res, dir_node->val);
		dir_node = dir_node->next;
	}

	list_clear(&dir_cpy);
	return res;
}

void substitute_args(t_listnode *wildcard_node, t_list *args, t_list *survived)
{
	t_listnode *w_node = survived->tail;
	while(w_node)
	{
		list_insert(args, wildcard_node, w_node->val);
		w_node = w_node->prev;
	}
}

void wildcard_resolve(t_list *tokens, t_shell *shell)
{
	t_list *dir = get_cwd_files();
	int i = 0;
	t_listnode *wild = tokens->head;
	t_list *reqs = NULL;

	wild = find_if(tokens->head, tokens->tail, is_wildcard);

	while(wild)
	{
		t_listnode *save = wild->next;
		if (!is_quoted_token(shell->quoted_tokens, wild) && (wild != tokens->head && !string_equal(wild->prev->val, "<<")))
		{
			reqs = make_list_from_string(wild->val, "*", all);

			t_list *survived = check_all_dirs(dir, reqs);

			if (!empty(survived))
			{
				substitute_args(wild, tokens, survived);
			}
			pop(tokens, wild);
			list_clear(&survived);
			list_clear(&reqs);
		}
		wild = save;
		wild = find_if(wild, tokens->tail, is_wildcard);
	}
	list_clear(&dir);
}
