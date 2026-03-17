# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 12:12:43 by nmagro-r          #+#    #+#              #
#    Updated: 2026/02/16 12:20:31 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

SRC =  main.cpp
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
	@echo "[ex02] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[ex02] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re