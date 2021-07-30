# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 17:16:02 by hhoyl             #+#    #+#              #
#    Updated: 2021/07/11 17:16:04 by hhoyl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run

NAME = philo

HEADER = philo.h

SRC = main.c parser.c utils.c forks.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra

OPTIONOBJ = -o

DEL = rm -rf

all: $(NAME)

$(NAME): $(HEADER) $(SRC)
	@$(CC) $(FLAG) $(SRC) $(OPTIONOBJ) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAG) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	
fclean: clean
	@$(DEL) $(NAME)

re: fclean all
