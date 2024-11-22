NAME = polymorph
C = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
FLAGS += -g 
FLAGS += -fsanitize=address

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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