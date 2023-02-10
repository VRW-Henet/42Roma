# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:18:05 by dpadrini          #+#    #+#              #
#    Updated: 2022/10/11 15:47:59 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = bonus
CC = gcc
SRC = check_util.c \
		findcomb.c \
		finder.c \
		init.c \
		moves.c \
		push_swap.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swaps.c \
		utilities.c \

SRC_CHECKER = checker.c \
				check_util.c \
				init.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				swaps.c \
				utilities.c

FLAG = -Wall -Werror -Wextra

LIBFT = ft_lib/libft.a
PRINTF = ft_lib/Printf/libftprintf.a
GNL = ft_lib/GetNextLine/getnextline.a

LIBS = $(LIBFT) $(PRINTF) $(GNL)

OBJ = $(SRC:.c=.o)
B_OBJ = $(SRC_CHECKER:.c=.o)

$(NAME): $(OBJ) $(LIBS)
		$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(FLAG) -c $< -o $@
		
$(LIBS): ft_lib/
		make -C ft_lib

$(BONUS): $(B_OBJ) $(LIBS)
		$(CC) $(FLAG) $(B_OBJ) $(LIBS) -o $(NAME)

all: $(NAME) $(BONUS)

clean: 
		rm -f $(OBJ) $(B_OBJ)

fclean: clean
		make fclean -C ft_lib

re: fclean all

.PHONY: all clean fclean re