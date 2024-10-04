/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_enums__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 16:26:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_ENUMS___H
# define __MINISHELL_ENUMS___H

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
