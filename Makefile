# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 10:42:10 by gkehren           #+#    #+#              #
#    Updated: 2022/06/16 13:05:40 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES:=	push_swap parsing sort_stack sort_utils rotate swap_push ft_split little_sort medium_sort sort_any
FILES_BONUS:=	checker parsing ft_split rotate swap_push checker_utils is_check

NAME:= push_swap
BONUS:= checker

# ------------------
CC:=clang
SRCPATH:=srcs/
BONUSPATH:=bonus/
HDRPATH:=include/
CCHPATH:=obj/
CCHPATH_BONUS:=obj/
IFLAGS:=-I ${HDRPATH}
CFLAGS:=-Wall -Wextra -Werror ${IFLAGS}
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_BONUS:=$(addprefix $(BONUSPATH),$(addsuffix .c,$(FILES_BONUS)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_BONUS:=$(addprefix $(CCHPATH_BONUS),$(addsuffix .o,$(FILES_BONUS)))
# ==================
CCHF:=.cache_exists

all: ${NAME} ${BONUS}

${NAME}: ${OBJ}
	@echo ${CYAN} " - Compiling $@" $(RED)
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo $(GREEN) " - OK" $(EOC)

${CCHPATH}%.o: ${SRCPATH}%.c | ${CCHF}
	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
	@${CC} ${CFLAGS} -c $< -o $@

${BONUS}: ${OBJ_BONUS}
	@echo ${CYAN} " - Compiling $@" $(RED)
	@${CC} ${CFLAGS} ${SRC_BONUS} -o ${BONUS}
	@echo $(GREEN) " - OK" $(EOC)

${CCHPATH_BONUS}%.o: ${BONUSPATH}%.c | ${CCHF}
	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
	@${CC} ${CFLAGS} -c $< -o $@

%.c:
	@echo ${RED}"Missing file : $@" ${EOC}

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf ${CCHPATH}
	@rm -f ${CCHF}

fclean:	clean
	@rm -f ${NAME}
	@rm -f ${BONUS}
	@rm -f ${NAME}.dSYM/
	@rm -f ${BONUS}.dSYM/

re:	fclean
	@${MAKE} all

.PHONY:	all clean fclean re
