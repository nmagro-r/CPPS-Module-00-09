NAME = PmergeMe

SRC = main.cpp \
	  PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "[PmergeMe] Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "[PmergeMe] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
