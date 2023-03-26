/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:41:09 by slakner           #+#    #+#             */
/*   Updated: 2023/03/26 16:53:08 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	win_close(t_img_data *img_data)
{
	mlx_close_window(img_data->mlx);
	return (0);
}

t_dpoint	rot90(t_dpoint v)
{
	double	tmp;

	tmp = -(v.x);
	v.x = v.y;
	v.y = tmp;
	return (v);
}

t_dpoint	rot270(t_dpoint v)
{
	t_dpoint	tmp;

	tmp = rot90(v);
	tmp = rot90(tmp);
	tmp = rot90(tmp);
	return (tmp);
}

// int dir should either be 1 or -1
// dir=1: move forward
// dir= -1: move backwards
void	move_forward_backward(t_img_data *img, int dir)
{
	t_dpoint	tmp;
	t_ipoint	map_sq;

	tmp.x = img->player.x + img->dir.x * img->move_speed * dir;
	tmp.y = img->player.y + img->dir.y * img->move_speed * dir;
	map_sq.x = tmp.x;
	map_sq.y = tmp.y;
	if (!(img->map[(img->map_x * map_sq.y) + map_sq.x]))
		img->player = tmp;
	draw_image(img->image, img);
}

// int dir should either be 1 or -1
// dir=1: move right
// dir= -1: move legt
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
	if (!(img->map[(img->map_x * map_sq.y) + map_sq.x]))
		img->player = pos_tmp;
	draw_image(img->image, img);
}

void	rotate_left(void *img_data)
{
	t_img_data	*img;

	img = (t_img_data *) img_data;
	img->dir = rot270(img->dir);
	img->cam_p = rot270(img->cam_p);
	draw_image(img->image, img);
}

void	rotate_right(void *img_data)
{
	t_img_data	*img;

	img = (t_img_data *) img_data;
	img->dir = rot90(img->dir);
	img->cam_p = rot90(img->cam_p);
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
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move_left_right(img, -1);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_left_right(img, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate_left(img);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate_right(img);
}