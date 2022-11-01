NAME = push_swap
BONUS = bonus
CC = gcc
SRC =	init.c \
		push_swap.c \
		utilities.c \
		engine.c \
		swaps.c \
		push_moves.c \
		rotations.c \
		reverse_rotations.c
SRC_BONUS =

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