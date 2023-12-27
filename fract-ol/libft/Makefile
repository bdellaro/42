# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:29:10 by bdellaro          #+#    #+#              #
#    Updated: 2023/12/22 09:48:26 by bdellaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =		libftprintf.a

SRCS =		ft_printf.c		\
		./ft_printf/ft_print_nbr.c		\
		./ft_printf/ft_print_str.c		\
		./ft_printf/ft_print_char.c		\
		./ft_printf/ft_print_ptr.c		\
		./ft_printf/ft_print_unsigned.c	\
		./ft_printf/ft_print_hexa.c		\
		./ft_printf/ft_print_percent.c	\

OBJS =		$(SRCS:.c=.o)

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -I./include

RM = 		rm -f

AR = 		ar crs

all:		$(NAME)

$(NAME): 	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:	
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean:		clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
