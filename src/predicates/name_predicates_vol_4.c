/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_parenthesis_token(t_listnode *token, t_shell *shell)
{
	return (is_opening_parenthesis_token(token, shell)
		|| is_closing_parenthesis_token(token, shell));
}

bool	not_parenthesis_token(t_listnode *token, t_shell *shell)
{
	return (!is_parenthesis_token(token, shell));
}
