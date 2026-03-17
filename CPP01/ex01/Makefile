# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME    = zombieHorde

SRC     = main.cpp Zombie.cpp zombieHorde.cpp
OBJ     = $(SRC:.cpp=.o)

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "🧹 Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "🧼 Executable removed."

re: fclean all

.PHONY: all clean fclean re
