NAME 	= SetFire

SUBDIRS = 
DIR_OBJ = ./obj

INCS 	= $(wildcard *.hpp $(foreach fd, $(SUBDIRS), $(fd)/*.hpp))
SRCS 	= Animal.cpp Annimal.cpp Cat.cpp Dog.cpp Car.cpp  Brain.cpp main.cpp
OBJS 	= $(addprefix $(DIR_OBJ)/, $(SRCS:.cpp=.o))

CC	 	= g++
FLAGS	= -Wall -Werror -Wextra -std=c++98

# Rules Beginning

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(DIR_OBJ)/%.o: %.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -c $< $(INC_DIRS)

clean:
	@rm -fr $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
