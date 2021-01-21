# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:41:31 by pllucian          #+#    #+#              #
#    Updated: 2021/01/20 18:38:49 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c ft_print_char.c ft_print_string.c ft_print_pointer.c	\
		ft_print_int.c ft_print_uint.c ft_print_hex.c ft_print_percent.c	\
		ft_set_flags.c ft_print_field.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

INCL = ft_printf.h

NAME = libftprintf.a

CC = gcc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o:		%.c $(INCL)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make bonus -C ./libft
			cp ./libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			make clean -C ./libft
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		bonus all clean fclean re
