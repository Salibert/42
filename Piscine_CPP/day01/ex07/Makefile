
.PHONY: re all clean fclean

CC=clang++ -std=c++98

CFLAGS= -Wall -Wextra -Werror

SRC= replace.cpp

OBJ=$(SRC:.cpp=.o)

NAME=replace

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf test.replace

re: fclean all