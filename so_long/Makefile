# 実行ファイル名
NAME	= so_long

# コンパイラとフラグ
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ソースファイル (.c)
# ゲーム本体のソースファイルを追加
SRCS	=	main.c \
			src/graphics.c \
			src/draw.c \
			textures/load_images.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			map/read_map.c \
			map/check_walls.c \
			map/check_components.c \
			map/check_chars.c \
			map/check_goal.c \
			map/check_valid_map.c # check_valid_map.c を追加

# オブジェクトファイル (.o) - ソースファイルから自動生成
OBJS	= $(SRCS:.c=.o)

# libft の設定
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# MiniLibX の設定
MLX_DIR		= minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# インクルードパス
INCLUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

# --- ルール ---

all: $(NAME)

# 実行ファイルのリンク
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) -L$(LIBFT_DIR) -lft

# libft のビルド
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# オブジェクトファイルのコンパイル
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# クリーンアップ
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
