/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/10 22:25:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	__cmd_exists__(const char *path, const char *name)
{
	struct stat	buffer;
	char		*guess;
	bool		res;

	guess = __make_string(path, "/", name, NULL);
	stat(guess, &buffer);
	res = (0 == access(guess, F_OK | X_OK) && !S_ISDIR(buffer.st_mode));
	__delete_string(&guess);
	return (res);
}
