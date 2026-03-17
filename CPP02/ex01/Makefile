# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME        = FixedPoint

SRC         = main.cpp Fixed.cpp
OBJ         = $(SRC:.cpp=.o)

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "[OK] Compiled $(NAME)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "[CLEAN] Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[FCLEAN] Executable removed"

re: fclean all

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all clean fclean re
