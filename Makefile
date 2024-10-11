NAME = minishell

SRCSPATH = ./src/lifecycle/ ./src/other/ ./src/builtin_utils ./src/builtins/ ./src/name_lookup/ ./src/exec/  \
			./src/syntax_analysis/ ./src/list_extensions/ ./src/cmd/ ./src/predicates/ ./src/ast/ \
			./cocobolo/cocobolo_src/ ./cocobolo/optional/ ./cocobolo/list/ \
			./cocobolo/get_next_line/ ./cocobolo/tree/ ./cocobolo/matrix/ ./cocobolo/set/

INCPATH = ./includes/ ./cocobolo/cocobolo_includes/ ./readline_local/include/
OBJSPATH = ./objs/

vpath %.c ${SRCSPATH}

SRCS = ./src/syntax_analysis/parenthesis_parse.c \
./src/syntax_analysis/redirection_parse.c \
./src/syntax_analysis/syntax_analysis.c \
./src/syntax_analysis/keyword_parse.c \
./src/syntax_analysis/quote_parse.c \
./src/list_extensions/shcount_if.c \
./src/list_extensions/shremove_if.c \
./src/list_extensions/shfind_if.c \
./src/lifecycle/make_heredoc.c \
./src/lifecycle/make_shell.c \
./src/lifecycle/destroys.c \
./src/lifecycle/make_export.c \
./src/lifecycle/make_desciptors.c \
./src/lifecycle/make_shlvl.c \
./src/lifecycle/make_path.c \
./src/other/__minishell__.c \
./src/other/main.c \
./src/other/signals_vol_2.c \
./src/other/signals_vol_1.c \
./src/other/wildcard_vol_1.c \
./src/other/read_line.c \
./src/other/wildcard_vol_2.c \
./src/other/status_modifiers.c \
./src/other/invalid_option.c \
./src/ast/insert_cmd_node.c \
./src/ast/ast_balance.c \
./src/ast/find_last_cmd.c \
./src/ast/ast_find_by_token.c \
./src/ast/ast_node_clear.c \
./src/ast/make_ast_empty.c \
./src/ast/make_ast.c \
./src/ast/make_cmd_node.c \
./src/ast/insert_ast_node.c \
./src/ast/make_file_node.c \
./src/ast/make_op_node.c \
./src/ast/find_last_process_cmd.c \
./src/ast/ast_clear.c \
./src/ast/ast_lrotate.c \
./src/ast/node_gettype.c \
./src/ast/ast_eval.c \
./src/ast/make_ast_skeleton.c \
./src/ast/ast_rrotate.c \
./src/predicates/name_predicates_vol_4.c \
./src/predicates/name_predicates_vol_3.c \
./src/predicates/name_predicates_vol_1.c \
./src/predicates/name_predicates_vol_7.c \
./src/predicates/name_predicates_vol_6.c \
./src/predicates/name_predicates_vol_2.c \
./src/predicates/name_predicates_vol_5.c \
./src/cmd/make_command.c \
./src/cmd/killall.c \
./src/cmd/cmd_predicates.c \
./src/cmd/make_cmd_arr.c \
./src/cmd/waitcmd.c \
./src/cmd/cmd_runtime_init.c \
./src/cmd/eval_prog.c \
./src/name_lookup/get_orig_val.c \
./src/name_lookup/redirect_helpers.c \
./src/name_lookup/recover_variables.c \
./src/name_lookup/merge_tokens_vol_2.c \
./src/name_lookup/merge_tokens_vol_1.c \
./src/name_lookup/merge_inside_quotes.c \
./src/name_lookup/get_pid.c \
./src/name_lookup/absolute_path_lookup.c \
./src/name_lookup/find_addr.c \
./src/name_lookup/open_file.c \
./src/name_lookup/save_orig_value.c \
./src/name_lookup/merge_tokens_utils.c \
./src/name_lookup/merge_redirections.c \
./src/name_lookup/preprocessing.c \
./src/name_lookup/cmd_lookup.c \
./src/name_lookup/dollar_sign_resolver.c \
./src/name_lookup/remove_spaces.c \
./src/name_lookup/cmd_lookup_helpers.c \
./src/name_lookup/sort_tokens.c \
./src/name_lookup/tokenizing.c \
./src/name_lookup/pop_redirections.c \
./src/name_lookup/resolve.c \
./src/name_lookup/redirect.c \
./src/builtins/pwd.c \
./src/builtins/cd_utils.c \
./src/builtins/builtin_preeval.c \
./src/builtins/cd.c \
./src/builtins/export_utils.c \
./src/builtins/echo.c \
./src/builtins/unset.c \
./src/builtins/exit.c \
./src/builtins/export.c \
./src/builtins/history.c \
./src/builtins/env.c \
./src/builtins/echo_utils.c \
./src/builtins/errcmd.c \
./cocobolo/cocobolo_src/__string_swap.c \
./cocobolo/cocobolo_src/__printc.c \
./cocobolo/cocobolo_src/__itoa.c \
./cocobolo/cocobolo_src/__malloc.c \
./cocobolo/cocobolo_src/__string_move.c \
./cocobolo/cocobolo_src/__strcmp_weak_n.c \
./cocobolo/cocobolo_src/__atoi_vol_2.c \
./cocobolo/cocobolo_src/__strlen.c \
./cocobolo/cocobolo_src/__putstr_fd.c \
./cocobolo/cocobolo_src/__colors_vol_2.c \
./cocobolo/cocobolo_src/__strchr.c \
./cocobolo/cocobolo_src/__fork.c \
./cocobolo/cocobolo_src/__delete_string.c \
./cocobolo/cocobolo_src/__strappend.c \
./cocobolo/cocobolo_src/__make_string.c \
./cocobolo/cocobolo_src/__strtrim.c \
./cocobolo/cocobolo_src/__putendl_fd.c \
./cocobolo/cocobolo_src/__str_ends_with.c \
./cocobolo/cocobolo_src/__colors_vol_1.c \
./cocobolo/cocobolo_src/__atoi_vol_1.c \
./cocobolo/cocobolo_src/__str_starts_with.c \
./cocobolo/cocobolo_src/__perror.c \
./cocobolo/cocobolo_src/__string_predicates.c \
./cocobolo/cocobolo_src/__ptoa.c \
./cocobolo/cocobolo_src/__close.c \
./cocobolo/cocobolo_src/__strcmp.c \
./cocobolo/cocobolo_src/__strstr.c \
./cocobolo/cocobolo_src/__exit.c \
./cocobolo/cocobolo_src/__pipe.c \
./cocobolo/cocobolo_src/__strdup.c \
./cocobolo/cocobolo_src/__strstr_n.c \
./cocobolo/cocobolo_src/__memset.c \
./cocobolo/cocobolo_src/__split.c \
./cocobolo/tree/tree_empty.c \
./cocobolo/tree/tree_find.c \
./cocobolo/tree/print_tree_vol_2.c \
./cocobolo/tree/find_min.c \
./cocobolo/tree/inorder.c \
./cocobolo/tree/tree_update.c \
./cocobolo/tree/find_max.c \
./cocobolo/tree/tree_main.c \
./cocobolo/tree/tree_size.c \
./cocobolo/tree/tree_generics.c \
./cocobolo/tree/print_tree_vol_1.c \
./cocobolo/tree/tree_predicates.c \
./cocobolo/tree/make_tree_node.c \
./cocobolo/tree/postorder.c \
./cocobolo/tree/tree_clear.c \
./cocobolo/tree/preorder.c \
./cocobolo/tree/get_val.c \
./cocobolo/tree/tree_remove_vol_2.c \
./cocobolo/tree/rotate.c \
./cocobolo/tree/tree_remove_vol_1.c \
./cocobolo/tree/swap_content.c \
./cocobolo/tree/make_tree.c \
./cocobolo/tree/tree_height.c \
./cocobolo/optional/value.c \
./cocobolo/optional/has_value.c \
./cocobolo/optional/set_optional.c \
./cocobolo/optional/any_of.c \
./cocobolo/optional/make_optional.c \
./cocobolo/get_next_line/get_next_line.c \
./cocobolo/get_next_line/get_next_line_utils.c \
./cocobolo/matrix/make_matrix_vol_2.c \
./cocobolo/matrix/matrix_alg.c \
./cocobolo/matrix/matrix_sort.c \
./cocobolo/matrix/matrix_clear.c \
./cocobolo/matrix/make_matrix_vol_1.c \
./cocobolo/list/push_front.c \
./cocobolo/list/find_vol_1.c \
./cocobolo/list/accumulate.c \
./cocobolo/list/make_list_vol_1.c \
./cocobolo/list/list_extract.c \
./cocobolo/list/traverse.c \
./cocobolo/list/count.c \
./cocobolo/list/make_list_vol_2.c \
./cocobolo/list/size.c \
./cocobolo/list/pop_back.c \
./cocobolo/list/find_vol_2.c \
./cocobolo/list/listnode_swap.c \
./cocobolo/list/list_insert.c \
./cocobolo/list/print_list_vol_1.c \
./cocobolo/list/print_list_vol_2.c \
./cocobolo/list/empty.c \
./cocobolo/list/erase.c \
./cocobolo/list/predicates.c \
./cocobolo/list/remove.c \
./cocobolo/list/front.c \
./cocobolo/list/push.c \
./cocobolo/list/pop_front.c \
./cocobolo/list/clear.c \
./cocobolo/list/back.c \
./cocobolo/list/push_back.c \
./cocobolo/list/list_emplace.c \
./cocobolo/list/make_node.c \
./cocobolo/set/set_remove.c \
./cocobolo/set/make_set.c \
./cocobolo/set/set_insert.c \
./cocobolo/set/set_count.c \
./cocobolo/set/set_clear.c \

OBJS = $(foreach D, ${SRCSPATH}, $(patsubst ${D}%.c, ${OBJSPATH}%.o, ${SRCS}))

# Basic colors
BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
PURPLE = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m

# Bold colors
BOLD_BLACK   = \033[1;30m
BOLD_RED     = \033[1;31m
BOLD_GREEN   = \033[1;32m
BOLD_YELLOW  = \033[1;33m
BOLD_BLUE    = \033[1;34m
BOLD_PURPLE = \033[1;35m
BOLD_CYAN    = \033[1;36m
BOLD_WHITE   = \033[1;37m

# Attributes
RESET   = \033[0m
BOLD    = \033[1m
UNDERLINE = \033[4m
REVERSE  = \033[7m

CC = gcc
# DEBUG = -fsanitize=address
DEBUG = -g
WFLAGS = -Wall -Wextra -Werror
CFLAGS = $(foreach H, $(INCPATH), -I$(H)) ${DEBUG} #${WFLAGS}

UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
	LREADLINE =  -Lreadline_local/lib -lreadline
else
	LREADLINE = -lreadline
endif

SRC_COUNT_TOT := $(shell expr $(shell find ./src/ ./cocobolo/ -name "*.c" | wc -l) + 0)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))


all : ${OBJSPATH} ${NAME}

${OBJSPATH} :
	@mkdir -p objs

${NAME} : print_info ${OBJS}
	@${CC} ${CFLAGS} ${OBJSPATH}*.o ${LREADLINE} -o $@
	@echo "\n\n${GREEN}            minishell compiled! ${RESET}\n"

${OBJSPATH}%.o : %.c Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%18s\r$(PURPLE)             [ %d/%d (%d%%) ]$(RESET)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@${CC} ${CFLAGS} -c $< -o $@


clean :
	@rm -rf ${OBJSPATH} ${OPTIONALOBJS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

# BRANCH = master

oda :
	make fclean
	git add .
	git commit -m "."
	git push ${BRANCH}

leaks : all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=.vlgignore ./${NAME}

config:
	mkdir -p readline_local
	./readline_config.sh readline_local

print_info:
	@printf "%b" "\n$(PURPLE)                $(NAME)$(RESET)\n\n"
	@printf "%b" "$(WHITE)      Authors : aamirkha, marikhac $(RESET)\n"
	@printf "\n"


.PHONY : all clean fclean re leaks config

