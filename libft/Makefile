# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 17:56:41 by trobert           #+#    #+#              #
#    Updated: 2022/02/21 15:39:57 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putnbr.c\
ft_putstr.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstadd_front.c\
ft_lstadd_back.c\
ft_lstsize.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstlast.c\
get_next_line_bonus.c\
get_next_line_utils_bonus.c\
ft_printf.c\
print_char.c\
print_int.c\
print_ptr.c\
print_unsigned.c\
utils.c\

SRCS = ${addprefix srcs/, ${SRC}}

OBJS = ${SRCS:.c=.o}

NAME = superlibft.a

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} a.out

re: fclean all

.PHONY: clean fclean bonus all re
