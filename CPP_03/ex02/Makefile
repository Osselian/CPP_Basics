NAME = fragTrap
C = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
FLAGS += -g 
FLAGS += -fsanitize=address

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp 
	$(C) $(FLAGS) $(SRC) -c 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all;

PHONY: all re clean fclean