# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:11:29 by dpadrini          #+#    #+#              #
#    Updated: 2022/06/24 10:03:02 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS += -Wall -Werror -Wextra

NAME = GetNextLine
ANAME = $(NAME).a

SRC = get_next_line_utils.c get_next_line.c

BUFFER = 42

BSIZE = -D BUFFER_SIZE=$(BUFFER)

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(ANAME) $(OBJ)

$(OBJ) :
		$(CC) $(FLAGS) $(BSIZE) -c get_next_line.h $(SRC)

clean: 
	rm -f $(OBJ)
	rm -f get_next_line.h.gch

fclean: clean 
	rm -f $(ANAME)

re: fclean all

.PHONY: all clean fclean re bonus