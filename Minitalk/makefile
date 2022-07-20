# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:32:39 by dpadrini          #+#    #+#              #
#    Updated: 2022/07/20 14:07:31 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME_S = server

NAME_BONUS = client_bonus
NAME_S_BONUS = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c

LIBFT = ft_lib/libft.a \
		ft_lib/Printf/libftprintf.a \

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: client server

bonus: client_bonus server_bonus

$(LIBFT): ft_lib/
		make -C ft_lib

client: $(LIBFT)
		$(CC) $(FLAGS) $(LIBFT) $(SRC_CLIENT) -o $(NAME)

server: $(LIBFT)
		$(CC) $(FLAGS) $(LIBFT) $(SRC_SERVER) -o $(NAME_S)

client_bonus: $(LIBFT)
		$(CC) $(FLAGS) $(LIBFT) $(SRC_CLIENT) -o $(NAME_BONUS)

server_bonus: $(LIBFT)
		$(CC) $(FLAGS) $(LIBFT) $(SRC_SERVER) -o $(NAME_S_BONUS)

clean:
	$(MAKE) clean -C ft_lib

fclean: clean
	rm -f server client server_bonus client_bonus
	$(MAKE) fclean -C ft_lib

re: fclean all

.PHONY: all clean fclean re bonus