.PHONE: all clean fclean

CC = gcc
CFLAGS= -Wall -Wextra -Werror -O3
INCLUDE= -I src/include
LDFLAGS= -shared
LPTHREAD= -lpthread
SRC= src/malloc.c \
	 src/ft_list_zone.c  \
	 src/utils.c \
	 src/free.c \
	 src/show_alloc_mem.c \
	 src/realloc.c

DIR_LIBFT=src/libft
LIBFT= -lft -L $(DIR_LIBFT)
LIB_MALLOC = -lft_malloc -L $(shell pwd)
LIB_PATH=$(PWD)

OBJECTS= $(SRC:.c=.o)

ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

ifeq ($(shell uname -s),Linux)
	OBJ_OPTIONS	:= -fPIC
	LDFLAGS	= -shared -Wl,-soname,
endif

NAME= libft_malloc_$(HOSTTYPE).so

all:$(NAME)

$(NAME):$(OBJECTS)
	@make -C $(DIR_LIBFT)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ $(LIBFT) $(INCLUDE) $(LPTHREAD)
	@ln -sf $(NAME) libft_malloc.so

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(OBJ_OPTIONS)

clean:
	@make clean -C $(DIR_LIBFT)
	@rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C $(DIR_LIBFT)
	@rm -rf $(NAME)
	@rm -rf libft_malloc.so

re: fclean all
