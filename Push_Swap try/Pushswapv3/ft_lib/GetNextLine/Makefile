# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:11:29 by dpadrini          #+#    #+#              #
#    Updated: 2023/01/20 13:20:57 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
FLAGS 	+= -Wall -Werror -Wextra

NAME 	= GetNextLine
ANAME 	= $(NAME).a

SRC 	= get_next_line_utils.c \
		get_next_line.c\

BUFFER 	= 42

BSIZE 	= -D BUFFER_SIZE=$(BUFFER)

OBJ 	= $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) $(BSIZE) -c $< -o $@

$(ANAME): $(OBJ)
	ar rcs $(ANAME) $(OBJ)

all: $(ANAME)

clean: 
	rm -f $(OBJ)
	rm -f get_next_line.h.gch

fclean: clean 
	rm -f $(ANAME)

re: fclean all

.PHONY: all clean fclean re bonus