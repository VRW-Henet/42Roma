# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 14:15:34 by dpadrini          #+#    #+#              #
#    Updated: 2022/01/15 18:08:23 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJS = $(SRCS:.c=.o)
HDRS = libft.h
FLAGS = -Wall -Wextra -Werror
$(NAME):
		gcc -c $(FLAGS) -I $(HDRS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
all:        $(NAME)
clean:
			rm -f $(OBJS)
fclean:     clean
			rm -f $(NAME)
re:         fclean all
.PHONY:     all clean fclean re