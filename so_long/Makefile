# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:15:06 by bdellaro          #+#    #+#              #
#    Updated: 2024/01/25 18:44:33 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =		so_long

SRC =		src/ft_main.c		\
		src/ft_init.c		\
#		src/ft_utils.c		\
#		src/ft_events.c		\
		
CC 		= cc
RM		= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		= -Wall -Wextra -Werror -I./include -O3
CLINKS		= -ldl -lglfw -pthread -lm -Llibft -lft

MLX			= MLX42
LIBMLX 		= $(MLX)/libmlx42.a

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	cmake $(MLX) -B $(MLX)	
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	cd libft;make clean
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(LIBMLX)
	cd libft;make fclean
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re
