# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 10:42:10 by gkehren           #+#    #+#              #
#    Updated: 2022/06/14 15:32:27 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	./srcs/push_swap.c ./srcs/parsing.c ./srcs/sort_stack.c ./srcs/sort_utils.c ./srcs/rotate.c ./srcs/swap_push.c ./srcs/ft_split.c ./srcs/little_sort.c ./srcs/medium_sort.c ./srcs/sort_any.c
SRCS_BONUS		=	./bonus/checker.c ./bonus/parsing.c ./bonus/ft_split.c ./bonus/rotate.c ./bonus/swap_push.c

OBJS			= ${SRCS:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

NAME			= push_swap

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} -I./srcs -o ${NAME} ${OBJS}

bonus:			${OBJS_BONUS}
						${CC} ${CFLAGS} -I./bonus -o checker ${OBJS_BONUS}

clean:
						${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
						${RM} ${NAME} checker

re:				fclean ${NAME}

.PHONY:			all bonus clean fclean re
