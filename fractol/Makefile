# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:34:00 by bdellaro          #+#    #+#              #
#    Updated: 2024/01/12 16:52:47 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =		fractol

SRCS =		src/ft_main.c		\
		src/ft_init.c		\
		src/ft_utils.c		\

OBJS =		$(SRCS:.c=.o)

CC = 		cc

CFLAGS =	-Wall -Wextra -Werror -I./include -O2

LIB =		-Lminilibx-linux -lmlx_Linux -Llibft -lft -lXext -lX11 -lm

RM = 		rm -f

all:		$(NAME)

$(NAME): 	$(OBJS)
		cd minilibx-linux;./configure
		cd libft;make
		${RM} Makefile.gen
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB}

clean:
		${RM} ${OBJS}
		cd libft;make clean
		cd minilibx-linux;make clean

fclean: clean
		${RM} ${NAME}
		cd libft;make fclean
		cd minilibx-linux;\
		./configure clean

re: fclean all
