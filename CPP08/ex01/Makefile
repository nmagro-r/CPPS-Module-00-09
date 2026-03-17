# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 12:51:30 by nmagro-r          #+#    #+#              #
#    Updated: 2026/02/14 12:53:20 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span
CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Span.cpp

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