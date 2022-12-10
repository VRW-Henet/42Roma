
NAME = push_swap
BONUS_NAME = checker

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

BONUS_SRC = checker.c \
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

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ) $(LIBS)
		$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(B_OBJ) $(LIBS)
		$(CC) $(FLAG) $(B_OBJ) $(LIBS) -o $(BONUS_NAME)

%.o: %.c push_swap.h
		$(CC) -o $@ $(FLAG) -c $<
		
$(LIBS): ft_lib/
		make -C ft_lib

clean: 
		rm -f *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(BONUS_NAME)
		make fclean -C ft_lib

re: fclean all

#.PHONY: all clean fclean re