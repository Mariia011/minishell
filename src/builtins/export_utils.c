/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:01:15 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/11 11:08:09 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	______i_a_g_t_c_i_m_p_f_n_________(char *expr,
				t_list *tokens, t_shell *shell);

static int	size_2(t_shell *shell, t_list *tokens);

static bool	not_equal_sign(t_listnode *const node)
{
	return (node && !string_equal(node->val, "="));
}

int	__export_from_string__(char *expr, t_shell *shell)
{
	t_list *tokens	__attribute__((cleanup(list_clear)));

	tokens = NULL;
	if (!expr || !shell)
		return (-1);
	tokens = make_list_from_string(expr, "=", all);
	if (empty(tokens))
		return (-1);
	if (______i_a_g_t_c_i_m_p_f_n_________(expr, tokens, shell) == -1)
		return (-1);
	if (size(tokens) >= 2)
		return (size_2(shell, tokens));
	else
	{
		unset_var(shell, tokens->head->val);
		tree_update(shell->export, tokens->head->val, NULL);
	}
	return (0);
}

static int	size_2(t_shell *shell, t_list *tokens)
{
	char *val	__attribute__((cleanup(__delete_string)));

	val = __make_string_from_list(tokens->head->next->next, back(tokens));
	if (val == NULL)
		val = __make_string_empty();
	return (export_update(shell, tokens->head->val, val));
}

static int	______i_a_g_t_c_i_m_p_f_n_________(char *expr,
		t_list *tokens, t_shell *shell)
{
	char	*old_val;

	if (tokens->head->val[__strlen(tokens->head->val) - 1] == '+')
	{
		tokens->head->val[__strlen(tokens->head->val) - 1] = '\0';
		old_val = get_val(shell->export, tokens->head->val);
		if (old_val == NULL)
			old_val = "";
		list_insert(tokens, tokens->head->next, old_val);
	}
	if (!is_name(tokens->head->val)
		|| NULL == find_if(tokens->head, back(tokens),
			not_equal_sign))
	{
		__va_perror("export: `", expr, "\': not a valid identifier", NULL);
		return (-1);
	}
	return (0);
}
