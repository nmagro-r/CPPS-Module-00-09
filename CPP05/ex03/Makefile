NAME = Intern
CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = AForm.cpp Bureaucrat.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\
		Intern.cpp\
		main.cpp

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