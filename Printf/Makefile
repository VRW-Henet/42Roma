# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:07:28 by dpadrini          #+#    #+#              #
#    Updated: 2022/02/18 11:35:33 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	+= -Wall -Werror -Wextra

NAME	= libftprintf
ANAME	= $(NAME).a

SRC	= ft_printf.c\
		check_flags.c\
		check_for_conversions.c\
		print_sc.c\
		print_p.c\
		print_id.c\
		print_u.c\
		print_xX.c\
		flags_at_zero.c\
		ft_strlen.c\
		check_n_print.c\
		look_for_flags.c\
		ft_putnbr_hex.c\
		ft_isdigit.c\
		len_num.c\
		len_num_hex.c\
		ft_putnbr.c\
		putnbr_ptr.c\
		printchar.c\
		printstr.c\
		print_stuff.c\
		printsymbol.c\
		print_hex.c\

OBJS	= $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

$(ANAME) : $(OBJS)
		ar -rc $(ANAME) $(OBJS)

all: $(ANAME)

bonus: all

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(ANAME)

re: fclean all

.PHONY: all clean fclean re bonus