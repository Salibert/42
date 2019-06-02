# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salibert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 15:35:44 by salibert          #+#    #+#              #
#    Updated: 2016/11/28 13:21:53 by salibert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re fclean clean

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	   srcs/ft_backtrack.c \
	   srcs/ft_ctetri1.c \
	   srcs/ft_ctetri2.c \
	   srcs/ft_ctetri3.c \
	   srcs/ft_ctetri4.c \
	   srcs/ft_errors.c \
	   srcs/ft_printtab.c \
	   srcs/ft_read.c \
	   srcs/ft_tabftetris.c \
	   srcs/ft_tetri1.c \
	   srcs/ft_tetri2.c \
	   srcs/ft_tetri3.c \
	   srcs/ft_tetri4.c \
	   srcs/ft_check.c \
	   srcs/ft_putchar.c \
	   srcs/ft_putstr.c \
	   srcs/ft_memset.c \
	   srcs/ft_strnew.c \
	   srcs/ft_strlen.c \
	   srcs/ft_memalloc.c \
	   srcs/ft_freetab.c \
	   srcs/ft_strdel.c \
	   srcs/ft_bzero.c

OBJECTS = main.o \
	   ft_backtrack.o \
	   ft_ctetri1.o \
	   ft_ctetri2.o \
	   ft_ctetri3.o \
	   ft_ctetri4.o \
	   ft_errors.o \
	   ft_printtab.o \
	   ft_read.o \
	   ft_tabftetris.o \
	   ft_tetri1.o \
	   ft_tetri2.o \
	   ft_tetri3.o \
	   ft_tetri4.o \
	   ft_check.o \
	   ft_putchar.o \
	   ft_putstr.o \
	   ft_memset.o \
	   ft_strnew.o \
	   ft_strlen.o \
	   ft_memalloc.o \
	   ft_freetab.o \
	   ft_strdel.o \
	   ft_bzero.o

all: $(NAME)

$(NAME):
	@gcc -I includes -c $(FLAGS) $(SRCS)
	@gcc -o $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
