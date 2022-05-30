# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 12:55:07 by dpadrini          #+#    #+#              #
#    Updated: 2022/05/24 12:13:10 by dpadrini         ###   ########.fr        #
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
	utilities.c

GNL = GetNextLine/get_next_line.c GetNextLine/get_next_line_utils.c

PF = Printf/chrchecker.c \
		Printf/conversions.c \
		Printf/ft_printf.c \
		Printf/sub_func_printf.c \
		Printf/utilities.c \
		Printf/utilities_b.c \

FT_PRINTF_A = libftprintf.a

LIBFT_A = libft.a

OBJ = $(SRC:.c=.o)

ANAME = $(NAME).a

%.o: %.c 
		$(CC) ${CFLAGS} -c $< -o $@

$(ANAME) : $(OBJ)
		ar -rc $(OBJ) $(B_OBJ)

fclean: clean 
		rm -f $(ANAME)
		rm -f Printf/*.o
		rm -f GetNextLine/*.o

re: fclean all

.PHONY: all clean fclean
