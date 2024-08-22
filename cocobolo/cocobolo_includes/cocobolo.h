/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocobolo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:40:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COCOBOLO_H
# define COCOBOLO_H

# include "get_next_line.h"
# include "list.h"
# include "optional.h"
# include "tree.h"
# include "pair.h"
# include "set.h"
# include <assert.h>
# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include <cdefs.h>

# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define ITALIC_ON "\e[3m"
# define ITALIC_OFF "\e[23m"

typedef struct s_list	t_list;
typedef struct s_node	t_node;

# ifdef __linux__
#  if __has_attribute(noreturn)
#   define __dead2 __attribute__((__noreturn__))
#  else
#   define __dead2
#  endif //  __has_attribute(noreturn)
# endif // __linux__


// usage : str = __strappend(str, s1, s2, ...)
# define __make_string(s, ...) __unwrapped_make_string__(s, __VA_ARGS__, NULL);

# define scoped_list t_list *__attribute__((cleanup(list_clear)))
# define scoped_matrix t_matrix __attribute__((cleanup(matrix_clear)))

typedef void			(*t_printf_option)(const char *const);

typedef bool			(*str_binary_predicate)(char *, char *);

typedef char			**t_matrix;

void					__perror(char *err);
void					__exit(char const *const err) __dead2;
void					*__malloc(size_t n) __attribute__((malloc)) __attribute__((warn_unused_result));
pid_t					__fork(void);
void					__pipe(int *p);
void					__putstr_fd(char *s, int fd);
void					*__memset(void *b, int c, size_t len);

// string
void					__string_swap(char **lhv, char **rhv);
void					__string_move(char **lhv, char **rhv);
void					__delete_string(char **s);
char					*__make_string_empty(void) __attribute__((malloc)) __attribute__((warn_unused_result));
char					*__make_string_from_char(const char c) __attribute__((malloc)) __attribute__((warn_unused_result));
char					*__strtrim(char *s1,
						char *set) __attribute__((malloc)) __attribute__((warn_unused_result));
char					*__make_string_from_list(t_node *first,
						t_node *last) __attribute__((malloc)) __attribute__((warn_unused_result));
char					*__attribute__((sentinel)) __attribute__((warn_unused_result)) __strappend(char *s,
							...);
void					__attribute__((sentinel)) __va_perror(char *s, ...);

char					*__attribute__((sentinel)) __attribute__((warn_unused_result)) __unwrapped_make_string__(char *s,
							...);
char					*__single_strappend__(char *lhv,
						char *rhv) __attribute__((warn_unused_result));
size_t					__strlen(const char *str);
char					*__strdup(const char *src) __attribute__((warn_unused_result));
char					*__strdup_until(const char *src,
						const char end) __attribute__((warn_unused_result));
char					*__strstr(char *haystack, char *needle);
ssize_t					__strcmp(const char *lhv, const char *rhv);
bool					__strchr(char *s, const char c);
char					*__strchr_p(char *s, bool (*p)(char));
bool					__strcmp_weak__(const char *lhv, const char *rhv);
char					*__itoa(int n) __attribute__((warn_unused_result));
char					*__ptoa(size_t n) __attribute__((warn_unused_result));

t_matrix				__split(char const *s, char *set) __attribute__((warn_unused_result));

char	*__single_append__(char *lhv, char *rhv);


// atoi
t_optional				__atoi(char const *str);
t_optional				__atol_strict(char const *str);
void					_skip_spaces(char const **const str);
int						_is_digit(char const c);
int						_is_sign(char const c);
long long				_process(long long res, char const c);
bool					_non_digit(char c);

// string predicates
bool					string_equal(char *lhv, char *rhv);
bool					string_less(char *lhv, char *rhv);
bool					string_greater(char *lhv, char *rhv);

// matrix
void					print_matrix(t_matrix arr);
void					matrix_clear(t_matrix *arrptr);
size_t					matrix_size(t_matrix arr);
t_matrix				make_matrix_from_string(char *s,
					char *set) __attribute__((warn_unused_result));
t_matrix				make_matrix_copy(t_matrix other) __attribute__((warn_unused_result));
t_matrix				make_matrix_from_list(t_list *list) __attribute__((warn_unused_result));
t_matrix				make_matrix_from_tree(t_tree *tree) __attribute__((warn_unused_result));
void					matrix_sort(t_matrix arr, str_binary_predicate cmp);

// colors
void					__attribute__((sentinel)) printc(const char *const message,
							...);
void					__italic__(const char *const message);
void					__purple__(const char *const message);
void					__cyan__(const char *const message);
void					__blue__(const char *const message);
void					__yellow__(const char *const message);
void					__green__(const char *const message);
void					__red__(const char *const message);
void					__reset__(const char *const message);

#endif // COCOBOLO_H
