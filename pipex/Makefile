# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:15:06 by bdellaro          #+#    #+#              #
#    Updated: 2024/03/05 16:48:08 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= pipex
NAME_B		= pipex_bonus

SRC_B	=	src/bonus/pipex_bonus.c		\
		src/bonus/pipex_utils_bonus.c	\

SRC	=	src/pipex.c		\
		src/pipex_utils.c	\

CC 		= gcc
RM		= rm -f

CFLAGS 		= -Wall -Wextra -Werror -g -I./include

CLINKS		= -ldl -lglfw -pthread -lm -Llibft -lft

OBJ 		= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)

all:	$(NAME)
bonus:	$(NAME_B)

$(NAME_B): $(OBJ_B)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(CLINKS)
	@echo "\033[1;32m[PIPEX_BONUS OK]\033[0m"


$(NAME): $(OBJ)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CLINKS)
	@echo "\033[1;32m[PIPEX OK]\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_B)
	-cd libft;make clean
	@echo "\033[1;32m[CLEAN OK]\033[0m"

fclean: clean
	cd libft;make fclean
	$(RM) $(NAME) $(NAME_B)
	@echo "\033[1;32m[FCLEAN OK]\033[0m"

re:	fclean all

.PHONY:		all bonus clean fclean re
