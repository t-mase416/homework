NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	main.c \
			src/error.c \

OBJS	= $(SRCS:.c=.o)
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
