NAME = RPN

SRC = main.cpp \
	  RPN.cpp

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
	@echo "[RPN] Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "[RPN] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
