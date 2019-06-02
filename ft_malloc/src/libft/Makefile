
ifeq ($(shell uname -s),Linux)
	OBJ_OPTIONS	:= -fPIC
endif

CC = gcc

SRC =	ft_print_addr_ptr.c \
		ft_putnbr_base.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_memcpy.c \
		ft_memset.c

O = $(SRC:.c=.o)

NAME  = libft.a


CFLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME):$(O)
	$(CC) $(CFLAGS) -c $(SRC) $(OBJ_OPTIONS)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
