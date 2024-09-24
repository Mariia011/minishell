/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 16:57:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	// parenthesis_parse(tokens, shell) == -1 || pipe_parse(tokens, shell) == -1 || redirection_parse(tokens, shell) == -1

bool syntax_analysis(t_list *tokens, t_shell *shell)
{
	return (

		parenthesis_parse(tokens, shell) && keyword_parse(tokens, shell)  && redirection_parse(tokens, shell)

	);
}
