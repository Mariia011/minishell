NAME = minishell

SRCSPATH = ./src/lifecycle/ ./src/other/ ./src/builtin_utils ./src/builtins/ ./src/name_lookup/ ./src/exec/  \
			./src/syntax_analysis/ ./src/list_extensions/ ./src/cmd/ ./src/ast/ \
			./cocobolo/cocobolo_src/ ./cocobolo/optional/ ./cocobolo/list/ \
			./cocobolo/get_next_line/ ./cocobolo/tree/ ./cocobolo/matrix/ ./cocobolo/set/

INCPATH = ./includes/ ./cocobolo/cocobolo_includes/ ./readline_local/include/
OBJSPATH = ./objs/

__SUPER_SECRET_GREETING__ = meow meow meow jupa jupa

vpath %.c ${SRCSPATH}

SRCS = $(foreach D, ${SRCSPATH}, $(wildcard ${D}*.c))
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
CFLAGS = $(foreach H, $(INCPATH), -I$(H)) ${DEBUG} -Werror #${WFLAGS}

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
# @say ${__SUPER_SECRET_GREETING__}

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

#

config:
	mkdir -p readline_local
	./readline_config.sh readline_local

print_info:
	@printf "%b" "\n$(PURPLE)                $(NAME)$(RESET)\n\n"
	@printf "%b" "$(WHITE)      Authors : aamirkha, marikhac $(RESET)\n"
	@printf "\n"


.PHONY : all clean fclean re leaks config
