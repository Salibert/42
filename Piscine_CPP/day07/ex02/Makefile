.PHONY: re all clean fclean

CFLAGS= -Wall -Wextra -Werror

SRC= main.cpp

OBJ=$(SRC:.cpp=.o)

NAME=a.out

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ -o $@ $^ $(CFLAGS)

%.o: %.cpp
	@clang++ -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all