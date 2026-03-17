NAME = ex00

SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "[ex00] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[ex00] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re