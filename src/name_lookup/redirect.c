/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:27:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_authorized_fds	redirect(t_ast_node *r, t_authorized_fds oldfds)
{
	t_authorized_fds	newfds;

	newfds = oldfds;
	if (r->redirection_type & (redirect_in | redirect_heredoc))
		__redirect_in__(&newfds, r);
	else if (r->redirection_type & (redirect_out | redirect_append))
	{
		if (string_equal(r->right->filename, "*")
			&& !find_addr(r->ast->shell->quoted_tokens, r->right->orig_token))
		{
			newfds.stdout.fd = -1;
			__va_perror("*: ambiguous redirect", NULL);
			r->right->fd = -1;
			return (newfds);
		}
		__redirect_out__(&newfds, r);
	}
	return (newfds);
}

int	process_infile(t_ast_node *r)
{
	return (open_file(r->right->filename, O_RDONLY));
}

int	process_outfile(t_ast_node *r)
{
	return (open_file(r->right->filename, O_WRONLY | O_CREAT | O_TRUNC));
}

int	process_heredoc(t_ast_node *r, t_shell *shell)
{
	return (make_heredoc(r->right->filename, shell,
			find_addr(shell->quoted_tokens, r->right->orig_token)));
}

int	process_append(t_ast_node *r)
{
	return (open_file(r->right->filename, O_WRONLY | O_CREAT | O_APPEND));
}
