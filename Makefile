# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 10:42:10 by gkehren           #+#    #+#              #
#    Updated: 2022/05/26 20:15:23 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	push_swap.c sort_stack.c rotate.c swap_push.c

OBJS			= ${SRCS:.c=.o}

NAME			= push_swap

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re
