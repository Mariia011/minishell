/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 20:54:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_infile(t_ast_node *r);
static int	process_outfile(t_ast_node *r);
static int	process_append(t_ast_node *r);
static int	process_heredoc(t_ast_node *r, t_shell *shell);

t_authorized_fds	redirect(t_ast_node *r, t_authorized_fds oldfds)
{
	t_authorized_fds newfds = oldfds;
	if (r->redirection_type & (redirect_in | redirect_heredoc))
	{
		dup2(r->ast->shell->stddesc->stdin, STDIN_FILENO);

		if (r->redirection_type & redirect_in)
			newfds.stdin.fd = (process_infile(r));
		else
			newfds.stdin.fd = (process_heredoc(r, r->ast->shell));
		newfds.stdin.author = r;

		dup2(newfds.stdin.fd, STDIN_FILENO);
		if (newfds.stdin.fd == -1 && (r->redirection_type & redirect_in))
		{
			if (find_addr(r->ast->shell->dollar_tokens, r->right->orig_token))
				__va_perror(get_orig_val(r->right->orig_token, r->ast->shell), ": ambiguous redirect", NULL);
			else if (string_equal(r->right->filename, "*") && !find_addr(r->ast->shell->quoted_tokens, r->right->orig_token))
				__va_perror("*: ambiguous redirect", NULL);
			else
				__va_perror(r->right->filename, ": ", "no such file or directory", NULL);
		}
		r->right->fd = newfds.stdin.fd;
	}
	else if (r->redirection_type & (redirect_out | redirect_append))
	{
		if (string_equal(r->right->filename, "*") && !find_addr(r->ast->shell->quoted_tokens, r->right->orig_token))
		{
			newfds.stdout.fd = -1;
			__va_perror("*: ambiguous redirect", NULL);
			r->right->fd = -1;
			return newfds;
		}
		if (r->redirection_type & redirect_out)
			newfds.stdout.fd = (process_outfile(r));
		else
			newfds.stdout.fd = (process_append(r));
		newfds.stdout.author = r;
		dup2(newfds.stdout.fd, STDOUT_FILENO);
		if (newfds.stdout.fd == -1)
		{
			if (find_addr(r->ast->shell->dollar_tokens, r->right->orig_token))
				__va_perror(get_orig_val(r->right->orig_token, r->ast->shell), ": ambiguous redirect", NULL);
			else
				__va_perror(r->right->filename, ": ", "could not open file", NULL);
		}
		r->right->fd = newfds.stdout.fd;
	}

	return newfds;
}

static int	process_infile(t_ast_node *r)
{
	return (open_file(r->right->filename, O_RDONLY));
}

static int	process_outfile(t_ast_node *r)
{
	return (open_file(r->right->filename, O_WRONLY | O_CREAT | O_TRUNC));
}

static int	process_heredoc(t_ast_node *r, t_shell *shell)
{
	return  make_heredoc(r->right->filename, shell,
			find_addr(shell->quoted_tokens, r->right->orig_token));
}

static int	process_append(t_ast_node *r)
{
	return (open_file(r->right->filename, O_WRONLY | O_CREAT | O_APPEND));
}
