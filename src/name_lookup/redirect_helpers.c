/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:19:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:20:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__redirect_out__(t_authorized_fds *newfds, t_ast_node *r)
{
	if (r->redirection_type & redirect_out)
		newfds->stdout.fd = (process_outfile(r));
	else
		newfds->stdout.fd = (process_append(r));
	newfds->stdout.author = r;
	dup2(newfds->stdout.fd, STDOUT_FILENO);
	if (newfds->stdout.fd == -1)
	{
		if (find_addr(r->ast->shell->dollar_tokens, r->right->orig_token))
			__va_perror(get_orig_val(r->right->orig_token, r->ast->shell),
				": ambiguous redirect", NULL);
		else
			__va_perror(r->right->filename, ": ", "could not open file", NULL);
	}
	r->right->fd = newfds->stdout.fd;
}

void	__redirect_in__(t_authorized_fds *newfds, t_ast_node *r)
{
	dup2(r->ast->shell->stddesc->stdin, STDIN_FILENO);
	if (r->redirection_type & redirect_in)
		newfds->stdin.fd = (process_infile(r));
	else
		newfds->stdin.fd = (process_heredoc(r, r->ast->shell));
	newfds->stdin.author = r;
	dup2(newfds->stdin.fd, STDIN_FILENO);
	if (newfds->stdin.fd == -1 && (r->redirection_type & redirect_in))
	{
		if (find_addr(r->ast->shell->dollar_tokens, r->right->orig_token))
			__va_perror(get_orig_val(r->right->orig_token, r->ast->shell),
				": ambiguous redirect", NULL);
		else if (string_equal(r->right->filename, "*")
			&& !find_addr(r->ast->shell->quoted_tokens, r->right->orig_token))
			__va_perror("*: ambiguous redirect", NULL);
		else
			__va_perror(r->right->filename, ": ", "no such file or directory",
				NULL);
	}
	r->right->fd = newfds->stdin.fd;
}
