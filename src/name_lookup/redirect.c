/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 22:12:52 by aamirkha         ###   ########.fr       */
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
	int x;
	if (r->redirection_type & (redirect_in | redirect_heredoc))
	{
		if (r->redirection_type & redirect_in)
			newfds.stdin.fd = (process_infile(r));
		else
			newfds.stdin.fd = (process_heredoc(r, r->ast->shell));
		newfds.stdin.author = r;
		x = newfds.stdin.fd;
		if ((!oldfds.stdin.author || oldfds.stdin.author->type != REDIRECTION))
			dup2(x, STDIN_FILENO);
		else if (x == -1 && r->redirection_type & redirect_in)
			__va_perror(r->right->filename, ": ", "no such file or directory", NULL);
	}
	else if (r->redirection_type & (redirect_out | redirect_append))
	{
		if (r->redirection_type & redirect_out)
			newfds.stdout.fd = (process_outfile(r));
		else
			newfds.stdout.fd = (process_append(r));
		newfds.stdout.author = r;
		x = newfds.stdout.fd;
		if ((!oldfds.stdout.author || oldfds.stdout.author->type != REDIRECTION))
			dup2(newfds.stdout.fd, STDOUT_FILENO);
		else if (x == -1)
			__va_perror(r->right->filename, ": ", "could not open file", NULL);
	}

	r->right->fd = x;

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
			is_quoted_token(shell->quoted_tokens, r->right->orig_token));
}

static int	process_append(t_ast_node *r)
{
	return (open_file(r->right->filename, O_WRONLY | O_CREAT | O_APPEND));
}
