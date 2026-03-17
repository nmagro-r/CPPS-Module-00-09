# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 17:53:53 by nmagro-r          #+#    #+#              #
#    Updated: 2025/10/29 17:53:57 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = weaponGame

SRC     = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ     = $(SRC:.cpp=.o)

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "[weaponGame] Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "[weaponGame] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
