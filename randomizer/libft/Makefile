#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:39:37 by bdellaro          #+#    #+#              #
#    Updated: 2024/04/30 11:59:58 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =		libft.a

SRC =		ft_error.c		\
		ft_free_array.c

OBJS =		$(SRC:.c=.o)

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -I../include/

RM = 		rm -f

AR =		ar crs

all:		$(NAME)

$(NAME): 	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
