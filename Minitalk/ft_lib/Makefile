# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 14:15:34 by dpadrini          #+#    #+#              #
#    Updated: 2022/07/20 11:03:07 by dpadrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft
ANAME	= $(NAME).a
CC	= gcc

CFLAGS	+= -Wall -Werror -Wextra

SRC = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putstr.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_memchr.c \
	   ft_strtrim.c \
	   ft_split.c \

OBJS	= $(SRC:.c=.o)

BONUS  = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c \

BONUS_OBJS	= $(BONUS:.c=.o)

PF = Printf/libftprintf.a

GNL = GetNextLine/GetNextLine.a

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(ANAME): $(OBJS) $(BONUS_OBJS)
	ar rcs $(ANAME) $(OBJS) $(BONUS_OBJS)
	make -C Printf
	make -C GetNextLine

all: $(ANAME) $(PF) $(GNL)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(ANAME)

fclean: clean
	rm -f $(OBJ)
	rm -f $(ANAME)
	make fclean -C Printf
	make fclean -C GetNextLine

re: fclean all

bonus: $(BONUS_OBJS)
	ar rcs $(ANAME) $(BONUS_OBJS)

.PHONY: all clean fclean re