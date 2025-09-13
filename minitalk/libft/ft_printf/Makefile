# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 17:56:23 by tmase             #+#    #+#              #
#    Updated: 2025/05/29 14:59:38 by tmase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf.c print_args.c utils.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
