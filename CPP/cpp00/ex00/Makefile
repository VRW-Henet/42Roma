# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 15:12:18 by dpadrini          #+#    #+#              #
#    Updated: 2023/06/26 15:12:21 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

$(NAME):
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

all: $(NAME)

re: fclean all