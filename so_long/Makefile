# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 14:15:06 by bdellaro          #+#    #+#              #
#    Updated: 2024/02/20 12:58:20 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= so_long
NAME_B		= so_long_bonus

SRC_B	=	src/bonus/bonus_main.c		\
		src/bonus/bonus_map.c		\
		src/bonus/bonus_check_map.c	\
		src/bonus/bonus_init.c		\
		src/bonus/bonus_card.c		\
		src/bonus/bonus_event.c		\
		src/bonus/bonus_utils.c		\
		src/bonus/bonus_utils_write.c	\
		src/bonus/bonus_utils_init.c	\
		src/bonus/bonus_utils_game.c	\
		src/bonus/bonus_parsing.c	\
		src/bonus/bonus_sup.c		\
		src/bonus/bonus_animation.c	\
		src/bonus/bonus_sprites.c	\
		src/bonus/bonus_path_sup.c	\
		src/bonus/bonus_sprites_sup.c	\

SRC	=	src/main.c		\
		src/map.c		\
		src/check_map.c		\
		src/init.c		\
		src/card.c		\
		src/event.c		\
		src/utils.c		\
		src/utils_write.c	\
		src/utils_init.c	\
		src/utils_game.c	\
		src/parsing.c		\

CC 		= cc
RM		= rm -f

CFLAGS 		= -Wall -Wextra -Werror -g -I./include -O3
CLINKS		= -ldl -lglfw -pthread -lm -Llibft -lft

MLX			= MLX42
LIBMLX 		= $(MLX)/libmlx42.a

OBJ 		= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)

all:	$(NAME)
bonus:	$(NAME_B)

$(NAME_B): $(LIBMLX) $(OBJ_B)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(LIBMLX) $(CLINKS)
	@echo "\033[1;32m[MAKE SO_LONG_BONUS OK]\033[0m"


$(NAME): $(LIBMLX) $(OBJ)
	cd libft;make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)
	@echo "\033[1;32m[MAKE SO_LONG OK]\033[0m"

$(LIBMLX):
	cmake $(MLX) -B $(MLX)
	$(MAKE) -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_B)
	-cd libft;make clean
	-cd $(MLX) && { \
		$(RM) Makefile cmake_install.cmake CMakeCache.txt; \
		test -d CMakeFiles && $(RM) -r CMakeFiles; \
		$(RM) mlx_frag_shader.c mlx_vert_shader.c; \
	}
	@echo "\033[1;32m[CLEAN OK]\033[0m"

fclean: clean
	$(RM) $(LIBMLX)
	cd libft;make fclean
	$(RM) $(NAME) $(NAME_B)
	@echo "\033[1;32m[FCLEAN OK, FOLDERS CLEARED]\033[0m"

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re
