# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:15:06 by bdellaro          #+#    #+#              #
#    Updated: 2024/04/30 09:40:59 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= push_swap

SRC	=	src/push_swap.c			\
		src/push_swap_utils.c	\
		src/fonctions_push.c	\
		src/fonctions_reverse.c	\
		src/fonctions_rotate.c	\
		src/fonctions_swap.c	\
		src/sort_five.c			\
		src/sort_little.c		\
		src/sort_big.c			\
		src/move.c				\
		src/init.c				\

CC 		= gcc
RM		= rm -f

CFLAGS 		= -Wall -Wextra -Werror -g -I./include

CLINKS		= -ldl -lglfw -pthread -lm -Llibft -lft

OBJ 		= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CLINKS)
	@echo "\033[1;32m[PUSH_SWAP OK]\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	-cd libft;make clean
	@echo "\033[1;32m[CLEAN OK]\033[0m"

fclean: clean
	cd libft;make fclean
	$(RM) $(NAME)
	@echo "\033[1;32m[FCLEAN OK]\033[0m"

re:	fclean all

.PHONY:		all bonus clean fclean re
