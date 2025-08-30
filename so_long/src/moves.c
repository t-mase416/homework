// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   moves.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/16 15:27:20 by tmase             #+#    #+#             */
// /*   Updated: 2025/08/18 19:08:59 by tmase            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// void	print_maps(char **map)
// {
// 	int y = 0;

// 	while (map[y])
// 	{
// 		printf("%s\n", map[y]);
// 		y++;
// 	}
// }

// void	move_up(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->map)
// 	x = game->player_x;
// 	y = game->player_y;
// 	game->map[x][y] = game->map[x][y - 1];
// 	game->map[x][y - 1] = 'P';
// 	draw_map(game);
// 	print_maps(game->map);
// }

// void	move_down(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->map)
// 	x = game->player_x;
// 	y = game->player_y;
// 	game->map[x][y] = game->map[x][y + 1];
// 	game->map[x][y + 1] = 'P';
// 	draw_map(game);
// 	print_maps(game->map);
// }

// void	move_left(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->map)
// 	x = game->player_x;
// 	y = game->player_y;
// 	game->map[x][y] = game->map[x - 1][y];
// 	game->map[x - 1][y] = 'P';
// 	draw_map(game);
// 	print_maps(game->map);
// }

// void	move_right(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	if (game->map)
// 	x = game->player_x;
// 	y = game->player_y;
// 	game->map[x][y] = game->map[x + 1][y];
// 	game->map[x + 1][y] = 'P';
// 	draw_map(game);
// 	print_maps(game->map);
// }

#include "so_long.h"

/*
** マップを探索してプレイヤー('P')の初期位置を見つけ、
** game構造体に保存する
*/
void	find_player_start(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*
** プレイヤーを新しい座標(new_x, new_y)に移動させる
*/
void	move_player(t_game *game, int new_x, int new_y)
{
	// 1. 移動先が壁('1')でないかチェック（当たり判定）
	if (game->map[new_y][new_x] == '1')
	{
		return; // 壁なら何もしない
	}

	// 2. 元のプレイヤー位置を床('0')に戻す
	game->map[game->player_y][game->player_x] = '0';

	// 3. 新しい位置にプレイヤー('P')を移動
	game->map[new_y][new_x] = 'P';

	// 4. game構造体のプレイヤー座標を更新する
	game->player_x = new_x;
	game->player_y = new_y;

	// 5. 移動回数をカウントし、コンソールに表示
	game->move_count++;
	printf("Move count: %d\n", game->move_count);

	// 6. 画面全体を再描画して移動を反映させる
	draw_map(game);
}
