# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:56:54 by nmagro-r          #+#    #+#              #
#    Updated: 2025/10/22 14:56:57 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= megaphone
SRC			= megaphone.cpp
OBJ			= $(SRC:.cpp=.o)

# **************************************************************************** #
#                                   Reglas                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# NUEVO → esta regla explica cómo crear un .o a partir de un .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
