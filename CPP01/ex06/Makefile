# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 16:50:37 by nmagro-r          #+#    #+#              #
#    Updated: 2025/11/10 19:02:59 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRC = main.cpp Harl.cpp
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
	@echo "[harlFilter] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[harlFilter] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re