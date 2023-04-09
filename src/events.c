/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:41:09 by slakner           #+#    #+#             */
/*   Updated: 2023/04/09 18:57:26 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	win_close(t_img_data *img_data)
{
	mlx_close_window(img_data->mlx);
	return (0);
}

// int dir should either be 1 or -1
// dir=1: move forward
// dir= -1: move backwards
void	move_forward_backward(t_img_data *img, int dir)
{
	t_dpoint	tmp;
	t_ipoint	map_sq;

	tmp.x = img->player.x + (img->dir.x * img->move_speed * dir);
	tmp.y = img->player.y + (img->dir.y * img->move_speed * dir);
	map_sq.x = tmp.x;
	map_sq.y = tmp.y;
	if (!(img->map[map_sq.y][map_sq.x]))
		img->player = tmp;
	draw_image(img->image, img);
}

// int dir should either be 1 or -1
// dir= -1: move right
// dir=  1: move left
void	move_left_right(t_img_data *img, int dir)
{
	t_dpoint	dir_tmp;
	t_dpoint	pos_tmp;
	t_ipoint	map_sq;

	if (dir == 1)
		dir_tmp = rot90(img->dir);
	else
		dir_tmp = rot270(img->dir);
	pos_tmp.x = img->player.x + dir_tmp.x * img->move_speed;
	pos_tmp.y = img->player.y + dir_tmp.y * img->move_speed;
	map_sq.x = pos_tmp.x;
	map_sq.y = pos_tmp.y;
	if (!(img->map[map_sq.y][map_sq.x]))
	{
		if (img->map[map_sq.y][map_sq.x + 1]
			&& map_sq.x + 1 - pos_tmp.x <= 0.2)
			pos_tmp.x -= 0.1;
		else if (img->map[map_sq.y][map_sq.x - 1]
			&& pos_tmp.x - map_sq.x <= 0.2)
			pos_tmp.x += 0.1;
		img->player = pos_tmp;
	}
	draw_image(img->image, img);
}

void	key_event(void *img_data)
{
	mlx_t		*mlx;
	t_img_data	*img;

	img = (t_img_data *) img_data;
	mlx = img->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		win_close(img);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		move_forward_backward(img, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		move_forward_backward(img, -1);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_left_right(img, -1);
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		move_left_right(img, 1);
}

void	leftright_key_hook(mlx_key_data_t keydata, void *img_data)
{
	t_img_data	*img;

	img = (t_img_data *) img_data;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_LEFT)
			rotate_right(img);
		else if (keydata.key == MLX_KEY_RIGHT)
			rotate_left(img);
	}
}
