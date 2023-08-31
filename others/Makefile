# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:43:19 by trobert           #+#    #+#              #
#    Updated: 2022/04/03 16:38:48 by zerudo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c\
		parse_map.c\
		check_map.c\
		init_game.c\
		display.c\
		display_bonus.c\
		display_night.c\
		events.c\
		movement.c\
		quit_reset_game.c\

SRCS = ${addprefix srcs/, ${SRC}}

OBJS = ${SRCS:.c=.o}

NAME = so_long

GMLX = ../minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ../minilibx-linux/include/

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

#${NAME}: ${OBJS}
#	${CC} ${FLAGS} ${OBJS} -o ${NAME}

#".c.o:
#	${CC} ${CFLAGS} -I./includes -Imlx_linux -O3 -c $< -o ${<:.c=.o}

${NAME}:
	${CC} ${FLAGS} ${SRCS} others/get_next_line_utils.c ../libft/superlibft.a ${GMLX} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
