# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 15:16:15 by dpadrini          #+#    #+#              #
#    Updated: 2023/02/10 15:16:26 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = main.c thread.c message.c philo_utility.c utility.c
FLG = -Wall -Werror -Wextra 

all:	$(NAME)

$(NAME):
		gcc $(FLG) -pthread $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re:		fclean all