/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_typedefs__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:50:20 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/04 20:27:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_TYPEDEFS___H
# define __MINISHELL_TYPEDEFS___H

typedef struct s_shell			t_shell;
typedef struct s_cmd			t_cmd;
typedef struct s_descriptor		t_descriptor;
typedef int						t_fd;
typedef enum e_cmd_type			t_cmd_type;
typedef enum e_eval_opcode		t_eval_opcode;
typedef enum e_cmd_type			t_cmd_type;

typedef char		*(*wildcard_fptr)(char *, char *);


typedef void					(*t_eval)(t_cmd *cmd);

#endif // __MINISHELL_TYPEDEFS___H
