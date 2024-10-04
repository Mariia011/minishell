/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:51:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/04 21:18:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <cocobolo.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node	t_listnode;
typedef struct s_list	t_list;
typedef char			*t_list_value;
typedef void			(*t_list_upredicate)(t_listnode *const);
typedef bool			(*t_list_upredicate_b)(t_listnode *const);
typedef bool			(*t_list_countpredicate)(const char *);
typedef bool			(*t_list_bpredicate_val)(const char *, const char *);
typedef void			(*t_list_apredicate_val)(size_t *, const char *);
typedef t_list_value	(*t_value_mutate)(t_list_value);

typedef enum e_opcode	t_opcode;

enum					e_opcode
{
	words_only,
	all
};

struct					s_list
{
	t_listnode	*head;
	t_listnode	*tail;
};

struct					s_node
{
	t_list_value			val;
	t_listnode				*next;
	t_listnode				*prev;
};

void					va_push_back(t_list *list, ...)
						__attribute__((sentinel));
void					va_push_front(t_list *list, ...)
						__attribute__((sentinel));
void					push_back(t_list *const list,
							const t_list_value x);
void					push_front(t_list *const list,
							const t_list_value x);

void					pop_front(t_list *const list);
void					pop_back(t_list *const list);

t_listnode				*front(t_list *list);
t_listnode				*back(t_list *list);
t_list					*make_list(void) __attribute__((malloc))
						__attribute__((warn_unused_result));
t_list					*make_list_copy(t_listnode *first, t_listnode *last,
							t_value_mutate f) __attribute__((malloc))
						__attribute__((warn_unused_result));
t_list					*make_list_copy_range(t_list *other,
							t_value_mutate f) __attribute__((malloc))
						__attribute__((warn_unused_result));
t_list					*make_list_from_matrix(char **arr)
						__attribute__((malloc))
						__attribute__((warn_unused_result));

t_list					*make_list_from_string(char *s, char *set,
							t_opcode opcode) __attribute__((malloc))
						__attribute__((warn_unused_result));

t_listnode				*make_node(const t_list_value x) __attribute__((malloc))
						__attribute__((warn_unused_result));
void					list_move_back(t_list *lhv, t_list *rhv);

void					print_list(t_list *list);
void					print_list_no_nl(t_list *list);
void					print_list_custom(t_list *list, t_list_upredicate p);
void					print_list_enumerate(t_list *list);

//	algorithms
size_t					size(t_list *list);
t_listnode				*find_if(t_listnode *first, t_listnode *last,
							t_list_upredicate_b p);
t_listnode				*find(t_listnode *first, t_listnode *last,
							t_list_value target, t_list_bpredicate_val cmp);
t_listnode				*find_range(t_list *list, t_list_value target,
							t_list_bpredicate_val cmp);
t_listnode				*find_strict(t_listnode *first, t_listnode *last,
							t_list_value target, t_list_bpredicate_val cmp);
size_t					count(t_listnode *first, t_listnode *last,
							t_list_value val);
size_t					count_range(t_list *list, t_list_value val);
size_t					count_if(t_listnode *first, t_listnode *last,
							t_list_countpredicate p);
size_t					accumulate(t_list *list, size_t sum_so_far,
							t_list_apredicate_val p);
void					pop(t_list *list, t_listnode *node);
size_t					erase(t_list *list, t_listnode *first,
							t_listnode *last);
size_t					list_remove(t_list *list, t_list_value val);
size_t					list_remove_if(t_list *list, t_list_value val,
							t_list_bpredicate_val p);
bool					empty(t_list *list);
t_listnode				*list_insert(t_list *list, t_listnode *pos, char *val);

void					list_clear(t_list **list);
void					list_extract(t_list *list, t_listnode *node);

//	traverse
void					preorder_traverse(t_listnode *head,
							t_list_upredicate f);
void					reverse_preorder_traverse(t_listnode *head,
							t_list_upredicate f);

void					postorder_traverse(t_listnode *head,
							t_list_upredicate f);
void					reverse_postorder_traverse(t_listnode *head,
							t_list_upredicate f);

void					listnode_swap(t_listnode *lhv, t_listnode *rhv);

//inserts like stl
t_listnode				*list_emplace(t_list *list, t_listnode *pos,
							t_listnode *node);

// predicates
bool					list_value_same(const char *lhv, const char *rhv);
bool					list_value_contains(t_list_value lhv, t_list_value rhv);

#endif // LIST_H
