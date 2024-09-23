/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_enums__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 19:38:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_ENUMS___H
# define __MINISHELL_ENUMS___H

enum	e_rdr
{
	in = 0,
	out = 1,
	redirect_in = 2,
	redirect_out = 4,
	redirect_heredoc = 8
};

enum	e_eval_opcode
{
	_nonivokable,
	_cd,
	_echo,
	_env,
	_export,
	_history,
	_pwd,
	_unset,
	_program,
	_msh_exit
};

enum e_cleanup_option
{
	asg,
	delete
};

#endif // __MINISHELL_ENUMS___H
