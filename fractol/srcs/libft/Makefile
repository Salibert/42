# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salibert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 11:05:13 by salibert          #+#    #+#              #
#    Updated: 2017/01/13 13:24:10 by salibert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_atoi.c ft_memcmp.c\
	  ft_putstr.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_putstr_fd.c\
	  ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_memdel.c ft_strcat.c ft_strlcat.c\
	  ft_strsplit.c ft_isalpha.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c\
	  ft_isascii.c ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c ft_isdigit.c\
	  ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c\
	  ft_strcpy.c ft_strncat.c ft_tolower.c ft_itoa.c ft_putendl.c ft_strdel.c\
	  ft_strncmp.c ft_toupper.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c\
	  ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_lstnew.c ft_lstdelone.c\
	  ft_lstdel.c  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_push_front.c ft_push_back.c\
	  ft_putstrtab.c ft_strjoinf.c ft_trim.c ft_freetab.c ft_putxy.c get_next_line.c\
	  ft_litoa.c ft_itoa_base.c ft_pow.c ft_ditoa.c
O = $(SRCS:.c=.o)

NAME  = libft.a


FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
