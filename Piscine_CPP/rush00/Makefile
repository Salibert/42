.PHONY: re all clean fclean

CC=clang++ -std=c++98 -lncurses

CFLAGS= -Wall -Wextra -Werror

SRC= AlienShip.cpp AlienWeapon.cpp AWeapon.cpp Enemy.cpp GameEntities.cpp List.cpp main.cpp Player.cpp PlayerWeapon.cpp BackGround.cpp \

OBJ=$(SRC:.cpp=.o)

NAME=ft_retro

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all