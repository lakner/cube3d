/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:41:09 by slakner           #+#    #+#             */
/*   Updated: 2023/03/12 20:53:00 by slakner          ###   ########.fr       */
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

void	key_event(void *img_data)
{
	mlx_t		*mlx;
	t_img_data	*img;

	img = (t_img_data*) img_data;
	mlx = img->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		win_close(img);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		img->player.x += img->dir.x * (1 + img->move_speed);
		img->player.y += img->dir.y * (1 + img->move_speed);
		draw_image(img->image, img);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		img->player.x -= img->dir.x * (1 + img->move_speed);
		img->player.y -= img->dir.y * (1 + img->move_speed);
		draw_image(img->image, img);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		t_dpoint tmp = rot270(img->dir);
		img->player.x += tmp.x * (1 + img->move_speed);
		img->player.y += tmp.y * (1 + img->move_speed);
		draw_image(img->image, img);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		t_dpoint tmp = rot90(img->dir);
		img->player.x += tmp.x * (1 + img->move_speed);
		img->player.y += tmp.y * (1 + img->move_speed);
		draw_image(img->image, img);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		img->dir = rot90(img->dir);
		img->cam_p = rot90(img->cam_p);
		img->dir = rot90(img->dir);
		img->cam_p = rot90(img->cam_p);
		img->dir = rot90(img->dir);
		img->cam_p = rot90(img->cam_p);
		draw_image(img->image, img);	
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		img->dir = rot90(img->dir);
		img->cam_p = rot90(img->cam_p);
		draw_image(img->image, img);
	}
}
