# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 12:55:07 by dpadrini          #+#    #+#              #
#    Updated: 2022/06/28 17:04:36 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRC = so_long.c \
	errors.c \
	map_reader.c \
	map_utilities.c \
	sl_checker.c \
	utilities.c \
	movements.c \
	animation.c

GNL = Libft/GetNextLine/GetNextLine.a

PF = Libft/Printf/libftprintf.a

LIBFT = Libft/libft.a

LIBS = $(LIBFT) $(PF) $(GNL)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) so_long.h
		$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBS) -o $(NAME)

%.o: %.c
		$(CC) ${CFLAGS} -c $< -o $@

$(LIBFT): Libft/ 
	make -C libft

$(GNL): Libft/GetNextLine/
	make -C Libft/GetNextLine

$(PF): libft/Printf/
	make -C Libft/Printf

all: $(LIBFT) $(PF) $(GNL) $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean 
		rm -f $(OBJ)
		make fclean -C libft 
		make fclean -C libft/Printf
		make fclean -C libft/GetNextLine
		rm -f so_long

re: fclean all

.PHONY: all clean fclean
