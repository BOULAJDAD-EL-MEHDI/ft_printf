# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 09:40:31 by eboulajd          #+#    #+#              #
#    Updated: 2025/11/09 10:12:25 by eboulajd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBH = libftprintf.h

SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_decimal.c \
	print_unsigned_decimal.c ft_print_lhex.c ft_print_uhex.c \
	ft_print_pointer.c ft_print_number.c ft_other_cases.c ft_strlen.c










OBJS = ${SRCS:.c=.o}

%.o: %.c ${LIBH}
	${CC} ${FLAGS} -c $< -o $@

${LIB}: ${OBJS} ${LIBH}
	ar -rcs ${LIB} ${OBJS}

all: ${LIB}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: clean
