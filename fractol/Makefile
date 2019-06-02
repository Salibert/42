# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salibert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 15:06:06 by salibert          #+#    #+#              #
#    Updated: 2017/01/13 14:43:23 by salibert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCFLAGS= -Wall -Wextra -Werror -march=native -O3 -o

LIBFT= -lft -L ./srcs/libft -I ./srcs/libft

LIBMLX= -lmlx -L ./srcs/minilibx_macos -I ./srcs/minilibx_macos

FRACTOL= -L

FRAMEWORK= -framework OpenGL -framework AppKit

SRC= ./srcs/main.c ./srcs/color.c ./srcs/threads.c ./srcs/ft_julia.c ./srcs/mandelbrot.c \
	./srcs/ft_boat.c ./srcs/screenshot.c ./srcs/touch.c ./srcs/affichage.c ./srcs/touch2.c




OBJ=$(SRCS:.c=.o)

NAME=fractol

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./srcs/libft
	@make -C ./srcs/minilibx_macos
	@clear
	@gcc $(CCFLAGS) $@ $(SRC) $(LIBFT) $(LIBMLX) $(FRAMEWORK)

%.o:%.c
	@gcc $(CCFLAGS) $@ -c $< $(LIBFT) $(LIBMLX)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
