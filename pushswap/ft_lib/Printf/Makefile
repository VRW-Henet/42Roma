# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:07:28 by dpadrini          #+#    #+#              #
#    Updated: 2022/06/22 14:10:18 by dpadrini         ###   ########.fr        #
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
	rm -f $(OBJ) $(B_OBJ) $(ANAME)

fclean: clean
	rm -f $(ANAME)

re: fclean all

.PHONY: all clean fclean re bonus