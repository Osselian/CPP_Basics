NAME = megaphone
C = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $(NAME)

%.o: %.cpp 
	$(C) $(FLAGS) $(SRC) -c 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean
	make all;

PHONY: all re clean fclean