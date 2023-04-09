/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:20:57 by slakner           #+#    #+#             */
/*   Updated: 2023/04/09 19:01:01 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_view_dir(t_img_data *img_data, double dir_x, double dir_y)
{
	img_data->dir.x = dir_x;
	img_data->dir.y = dir_y;
}

void	set_cam_plane(t_img_data *img_data, double cam_x, double cam_y)
{
	img_data->cam_p.x = cam_x;
	img_data->cam_p.y = cam_y;
}

void	init_view_dir(t_img_data *img_data, char dir)
{
	if (dir == 'E')
	{
		set_view_dir(img_data, 1, 0);
		set_cam_plane(img_data, 0, 0.66);
	}
	else if (dir == 'N')
	{
		set_view_dir(img_data, 0, -1);
		set_cam_plane(img_data, 0.66, 0);
	}
	else if (dir == 'W')
	{
		set_view_dir(img_data, -1, 0);
		set_cam_plane(img_data, 0, -0.66);
	}
	else if (dir == 'S')
	{
		set_view_dir(img_data, 0, 1);
		set_cam_plane(img_data, -0.66, 0);
	}
}

t_img_data	init_img_data(t_data *data, mlx_t *mlx, mlx_image_t *img)
{
	t_img_data	img_data;

	img_data.texture[NORTH] = mlx_load_png(data->no_fn);
	img_data.texture[SOUTH] = mlx_load_png(data->so_fn);
	img_data.texture[EAST] = mlx_load_png(data->ea_fn);
	img_data.texture[WEST] = mlx_load_png(data->we_fn);
	img_data.screen_width = SCREEN_X;
	img_data.screen_height = SCREEN_Y;
	img_data.map_x = data->width;
	img_data.map_y = data->height;
	img_data.player.x = data->player_x + 0.5;
	img_data.player.y = data->player_y + 0.5;
	img_data.ground_color = rgb_to_hex(data->f_colors);
	img_data.sky_color = rgb_to_hex(data->c_colors);
	init_view_dir(&img_data, data->player_o);
	img_data.move_speed = 0.15;
	img_data.map = data->map_int;
	img_data.mlx = mlx;
	img_data.image = img;
	return (img_data);
}
