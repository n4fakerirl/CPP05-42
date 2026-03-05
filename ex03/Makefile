# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 02:08:04 by ocviller          #+#    #+#              #
#    Updated: 2026/03/05 09:32:01 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
NAME = form28B
SRC = AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
OBJ = AForm.o main.o RobotomyRequestForm.o Bureaucrat.o PresidentialPardonForm.o ShrubberyCreationForm.o
OPTIONS = -o $(NAME)

all: $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(OPTIONS)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re