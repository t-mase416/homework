NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	main.c \
			src/draw.c \
			src/images.c \
			src/event.c \
			src/setup.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			map/read_map.c \
			map/check_walls.c \
			map/check_components.c \
			map/check_chars.c \
			map/check_goal.c \
			map/check_valid_map.c \
			map/utils.c \

OBJS	= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) -L$(LIBFT_DIR) -lft

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
