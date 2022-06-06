# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 10:42:10 by gkehren           #+#    #+#              #
#    Updated: 2022/06/06 13:31:01 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	push_swap.c parsing.c sort_stack.c sort_utils.c rotate.c swap_push.c ft_split.c little_sort.c medium_sort.c sort_any.c

OBJS			= ${SRCS:.c=.o}

NAME			= push_swap

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3 -I.

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re
