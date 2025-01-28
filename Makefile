# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naorakot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 15:53:25 by naorakot          #+#    #+#              #
#    Updated: 2025/01/22 16:00:20 by naorakot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS=-Wall -Werror -Wextra
NAME=pipex
LIB=libby.h
SRC=distrib.c\
    parsing.c\
    utils.c\
    where.c\
    main.c\
    split.c

all: $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) -o $(NAME) $(FLAGS) $(SRC)

clean:
	rm -f pipex

fclean: clean

re: fclean all

.PHONY: all clean re fclean 
