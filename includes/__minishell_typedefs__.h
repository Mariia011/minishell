/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_typedefs__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:50:20 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/23 16:08:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_TYPEDEFS___H
# define __MINISHELL_TYPEDEFS___H

typedef struct s_shell			t_shell;
typedef struct s_cmd			t_cmd;
typedef struct s_cmd_container	t_cmd_container;
typedef struct s_descriptor		t_descriptor;
typedef int						t_fd;
typedef enum e_cmd_type			t_cmd_type;
typedef enum e_eval_opcode		t_eval_opcode;

typedef void					(*t_eval)(t_cmd *cmd);

#endif // __MINISHELL_TYPEDEFS___H
