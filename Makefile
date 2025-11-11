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
