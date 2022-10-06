# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:18:05 by dpadrini          #+#    #+#              #
#    Updated: 2022/10/06 14:45:33 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
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
				check_utilis.c \
				init.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				swaps.c \
				utilities.c

FLAG = -Wall -Werror -Wextra
LIBFT = ft_lib/libft.a

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): make re -C ft_lib
		gcc $(FLAG) -o $(NAME) $(SRC) $(LIBFT)

bonus: make re -C ft_lib
		gcc $(FLAG) -o $(NAME) $(SRC_CHECKER) $(LIBFT)

all: $(NAME) bonus

clean: rm -f (NAME) $(BONUS)

fclean: clean
		make fclean -C ft_lib

re: fclean all

.PHONY: all clean fclean re