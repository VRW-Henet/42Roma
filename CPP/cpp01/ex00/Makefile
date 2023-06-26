NAME = zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
FLAG = -Wall -Wextra -Werror -std=c++98

$(NAME):
	g++ $(FLAG) $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

all: $(NAME)

re: fclean all