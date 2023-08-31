# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:43:19 by trobert           #+#    #+#              #
#    Updated: 2022/03/29 16:52:41 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c\
		parse_map.c\
		check_map.c\
		init_game.c\
		display.c\
		events.c\
		check_screen_size.c\
		movement.c\
		movement2.c\
		quit_game.c\

BSRC =	main_bonus.c\
		parse_map_bonus.c\
		check_map_bonus.c\
		check_screen_size_bonus.c\
		init_game_bonus.c\
		display_bonus.c\
		display_extra_bonus.c\
		events_bonus.c\
		movement_bonus.c\
		movement2_bonus.c\
		quit_reset_game_bonus.c\
		anim_bonus.c\

SRCS = ${addprefix srcs/, ${SRC}}

BSRCS = ${addprefix srcs_bonus/, ${BSRC}}

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRCS:.c=.o}

INC = -I./includes -I./minilibx-linux -I./libft/includes

NAME = so_long

BNAME = so_long_bonus

LIBFT = libft/superlibft.a

MINILIBX = minilibx-linux/libmlx_Linux.a

CC = cc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lXext -lX11

MAKELIB = make -C libft/

MAKELIBX = make -C minilibx-linux/

CLEANLIB = make fclean -C libft/

CLEANLIBX = make clean -C minilibx-linux/

all: libcompil ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${INC} ${MINILIBX} ${LIBFT} ${MLXFLAGS} -o ${NAME}

.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

bonus: libcompil ${BNAME}

$(BNAME): ${BOBJS}
	${CC} ${CFLAGS} ${BOBJS} ${INC} ${MINILIBX} ${LIBFT} ${MLXFLAGS} -o ${BNAME}

libcompil :
	${MAKELIB}
	${MAKELIBX}

clean:
	${RM} ${OBJS} ${BOBJS}

fclean: clean libclean
	${RM} ${NAME} ${BNAME}

libclean:
	${CLEANLIB}
	${CLEANLIBX}

re: fclean all

.PHONY: clean fclean bonus all re
