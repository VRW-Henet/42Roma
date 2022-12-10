NAME = push_swap
BONUS = checker
CC = gcc
SRC =	pushswap.c \
		instruction.c \
		engine.c \
		fake_pull.c \
		init.c \
		mallocation.c \
		push_moves.c \
		reverse_rotations.c \
		rotations.c \
		swaps.c \
		utilities.c \
		utilities_b.c \
		minmidmax.c

BONUS_SRC = bonus.c \
			push_moves.c \
			rotations.c \
			reverse_rotations.c \
			swaps.c \
			init.c \
			utilities.c \
			instruction.c \
			mallocation.c 

FLAG = -Wall -Werror -Wextra

LIBFT = ft_lib/libft.a
PRINTF = ft_lib/Printf/libftprintf.a
GNL = ft_lib/GetNextLine/GetNextLine.a

LIBS = $(LIBFT) $(PRINTF) $(GNL)

OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS_SRC:.c=.o)

$(NAME): $(OBJ) $(LIBS)
		$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(BONUS): $(B_OBJ) $(LIBS)
		$(CC) $(FLAG) $(B_OBJ) $(LIBS) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(FLAG) -c $< -o $@
		
$(LIBS): ft_lib/
		make -C ft_lib

all: $(NAME) $(BONUS)

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(B_OBJ)
		rm $(NAME)
		rm $(BONUS)
		make fclean -C ft_lib

re: fclean all

.PHONY: all clean fclean re