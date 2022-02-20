# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:07:28 by dpadrini          #+#    #+#              #
#    Updated: 2022/02/20 11:04:32 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	+= -Wall -Werror -Wextra

NAME	= libftprintf
ANAME	= $(NAME).a

SRC	= ft_printf.c\
		chrchecker.c\
		conversions.c\
		sub_func_printf.c\
		utilities_b.c\
		utilities.c\

OBJ	= $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(ANAME) : $(OBJ)
		ar -rc $(ANAME) $(OBJ)

all: $(ANAME)

bonus: all

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(ANAME)

re: fclean all

.PHONY: all clean fclean re bonus