# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 18:12:20 by ayarmaya          #+#    #+#              #
#    Updated: 2024/04/06 04:46:03 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
PATH_SRC	=	src/
SRC			=	ft_push.c \
				ft_swap.c \
				ft_rotate.c \
				ft_reverse.c \
				ft_little_sort.c \
				ft_big_sort.c \
				ft_sort_five.c \
				ft_init.c \
				ft_move.c \
				ft_main.c
SRCS		=	$(addprefix $(PATH_SRC), $(SRC))
OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	libft/libft.a
HEADERS		=	-I./include -I./libft/include
RM			= 	rm -f

all:		$(NAME)

$(NAME): 	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(HEADERS)

%.o: 		%.c
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			make -C libft clean

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re
