NAME = philo_bonus
SRC = main.c thread.c message.c utility.c
FLG = -Wall -Werror -Wextra 

all:	$(NAME)

$(NAME):
		gcc $(FLG) -pthread $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re:		fclean all