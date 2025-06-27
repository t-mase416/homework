NAME	= solong

# コンパイラとフラグ
CC		= cc
# CFLAGS	= -Wall -Wextra -Werror

# ソースとオブジェクト
SRC		= main.c
OBJ		= $(SRC:.c=.o)

# MiniLibX 設定
MLX_DIR	= minilibx-linux
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_INC	= -I$(MLX_DIR)

# libft 設定
LIBFT_DIR = libft
LIBFT	= $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# インクルード
INCLUDES = $(MLX_INC) $(LIBFT_INC)

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
