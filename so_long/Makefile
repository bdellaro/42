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

CFLAGS 		= -Wall -Wextra -Werror -I./include -O3
CLINKS		= -ldl -lglfw -pthread -lm -Llibft -lft

MLX			= MLX42
LIBMLX 		= $(MLX)/libmlx42.a

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)
	@echo "\033[0;32mMake OK, program ready tu use !\033[0m"

# $(MLX):
# 	cmake $(MLX) -B $(MLX)	

$(LIBMLX):
	cmake $(MLX) -B $(MLX)
	$(MAKE) -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	-cd libft;make clean
	-cd $(MLX) && { \
		$(RM) Makefile cmake_install.cmake CMakeCache.txt; \
		test -d CMakeFiles && $(RM) -r CMakeFiles; \
		$(RM) mlx_frag_shader.c mlx_vert_shader.c; \
	}
	@echo "\033[0;32mMake clean command OK...\033[0m"

fclean: clean
	$(RM) $(LIBMLX)
	cd libft;make fclean
	$(RM) $(NAME)
	@echo "\033[0;32mMake fclean command OK, folders cleared !\033[0m"

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re
