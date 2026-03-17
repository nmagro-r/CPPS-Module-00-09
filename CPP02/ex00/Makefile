NAME    = fixedPoint

SRC     = main.cpp Fixed.cpp
OBJ     = $(SRC:.cpp=.o)

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "[Fixed] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[Fixed] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re