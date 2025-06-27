/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:26:18 by tmase             #+#    #+#             */
/*   Updated: 2025/06/27 15:14:52 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include "so_long.h"
#include <math.h>


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	draw_line(t_data *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int rate_of_change = (y1 - y0) / (x1 - x0);
// 	while (x0 < x1)
// 	{
// 		my_mlx_pixel_put(img, x0, (x0 * rate_of_change), color);
// 		x0++;
// 	}
// }

// void	draw_circle(t_data *img, int cx, int cy, int radius, int color)
// {
// 	double angle = 0;
// 	double step = 0.01;

// 	while (angle < 2 * M_PI)
// 	{
// 		int x = (int)(cx + radius * cos(angle));
// 		int y = (int)(cy + radius * sin(angle));
// 		my_mlx_pixel_put(img, x, y, color);
// 		angle += step;
// 	}
// }

// void	draw_triangle(t_data *img, int x, int y, int color)
// {
// 	draw_line(img, 0, 500, 500, 500, 0x0FF0000);
// 	// draw_line(img, 250, 0, 500, 250, 0x0FF0000);
// }

// int key_hook(void)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello World");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	draw_circle (&img, 250, 250, 100, 0x00FF0000);
// 	draw_line(&img, 0, 0, 500, 500, 0x000FF00);
// 	draw_triangle(&img, 0, 0, 0x00FF00);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	
	mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);

	mlx_loop(vars.mlx);
}
