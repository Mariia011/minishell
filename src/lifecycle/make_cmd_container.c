/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:35:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/24 01:21:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// static t_list	*make_partition(t_shell *shell, t_node *first, t_node *last);
// static void		make_cmds(t_cmd_container *container, t_shell *shell,
// 					t_list *tokens);

// t_cmd_container	*make_cmd_container(char *raw_cmd, t_shell *shell)
// {
// 	t_list			*tokens;
// 	t_cmd_container	*container;

// 	tokens = preprocess(tokenize(raw_cmd), shell);
// 	if (empty(tokens) || !shell)
// 	{
// 		list_clear(&tokens);
// 		return (NULL);
// 	}
// 	if (count_range(tokens, "<<") > HEREDOC_MAX)
// 	{
// 		list_clear(&tokens);
// 		__t_shell__(shell);
// 		__perror("maximum here-document count exceeded");
// 		exit(2);
// 	}
// 	container = __malloc(sizeof(t_cmd_container));
// 	container->tokens = tokens;
// 	container->current_cmd_index = 0;
// 	container->shell = shell;
// 	container->fds = __calloc(count_if(tokens->head, tokens->tail, is_redirection) * sizeof(int)); // what if malloc 0?
// 	container->size = count_pipes(tokens, shell) + 1;
// 	container->arr = __calloc(sizeof(t_cmd) * container->size);
// 	container->shell->container = container;
// 	preprocess_redirections(tokens, container);

// 	wildcard_resolve(tokens, shell);

// 	make_cmds(container, shell, tokens);
// 	list_clear(&container->tokens);
// 	container->tokens = NULL;
// 	return (container);
// }

// static void	make_cmds(t_cmd_container *container, t_shell *shell,
// 		t_list *tokens)
// {
// 	size_t	i;
// 	t_node	*first;
// 	t_node	*pipe;
// 	t_list	*partition;

// 	i = 0;
// 	first = tokens->head;

// 	while (i < container->size)
// 	{
// 		pipe = find_next_pipe(first, tokens, shell);
// 		if (!pipe)
// 			pipe = back(tokens);
// 		else
// 		{
// 			pipe = pipe->prev;
// 			pop(tokens, pipe->next);
// 		}
// 		partition = make_partition(shell, first, pipe);
// 		container->arr[i] = make_command(partition, container, shell);
// 		list_clear(&partition);
// 		first = pipe->next;
// 		i++;
// 	}
// }

// static t_list	*make_partition(t_shell *shell, t_node *first, t_node *last)
// {
// 	t_list	*list;
// 	t_node	*curr;

// 	if (!shell || !first || !last)
// 		return (NULL);
// 	list = make_list();
// 	curr = first;
// 	while (curr && curr->prev != last)
// 	{
// 		push_back(list, curr->val);
// 		if (is_quoted_token(shell->quoted_tokens, curr))
// 		{
// 			save_token(shell, back(list));
// 		}
// 		curr = curr->next;
// 	}
// 	return (list);
// }
