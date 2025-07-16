NAME	= solong

CC		= cc
# CFLAGS	= -Wall -Wextra -Werror

# ゲーム本体のメインファイル
GAME_MAIN_SRC 	= main.c
# GNL ソースファイル
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
# MAP ソースファイル
MAP_SRCS = map/read_map.c map/check_walls.c map/check_components.c map/check_chars.c map/check_goal.c

# MiniLibX 設定
MLX_DIR	= minilibx-linux
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_INC	= -I$(MLX_DIR)

# libft 設定
LIBFT_DIR = libft
LIBFT	= $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

INCLUDES = $(MLX_INC) $(LIBFT_INC)

# オブジェクトファイル定義
GNL_OBJS = $(GNL_SRCS:.c=.o)
MAP_OBJS = $(MAP_SRCS:.c=.o)
GAME_MAIN_OBJ = $(GAME_MAIN_SRC:.c=.o)

# 実行ファイル作成
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(MLX) $(LIBFT)

# libft をビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)



# オブジェクトのビルド
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# クリーン
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
