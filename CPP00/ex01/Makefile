# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:56:39 by nmagro-r          #+#    #+#              #
#    Updated: 2025/10/22 14:56:43 by nmagro-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = MyAwesomePhoneBook

SRC     = main.cpp PhoneBook.cpp Contact.cpp
OBJ     = $(SRC:.cpp=.o)

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "[PhoneBook] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[PhoneBook] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re