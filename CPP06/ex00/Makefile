NAME = convert
CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all