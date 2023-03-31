/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:04:40 by slakner           #+#    #+#             */
/*   Updated: 2023/03/30 21:40:59 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "cub3d.h"
#include "draw_pixel_col.h"
#include "../libft/include/libft.h"

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
	img_data.move_speed = 0.15;
	img_data.cam_p.x = 0;
	img_data.cam_p.y = 0.66;
	img_data.dir.x = -1;
	img_data.dir.y = 0;
	img_data.map = data->map_int;
	img_data.mlx = mlx;
	img_data.image = img;
	return (img_data);
}

//****** void	draw_image(mlx_image_t *image,  t_img_data *img_data) ******
// draws the current frame,  one column of pixels at a time
//double cam_x:	coordinate in camera space: width of the screen
//				scaled to range -1...1,  with 0 at the center of the screen
//int x:		x coordinate of pixel on screen
void	draw_image(mlx_image_t *image, t_img_data *img_data)
{
	uint32_t	x;

	x = 0;
	while (x < img_data->screen_width - 1)
	{
		draw_pixel_col(image, img_data, x);
		x++;
	}
}

uint32_t	get_texture_color(t_img_data *img,
				double tex_pos, int tex_x, int walldir)
{
	int			tex_y;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	color;

	tex_y = (int)(tex_pos) & (img->texture[walldir]->height - 1);
	r = img->texture[walldir]->pixels[
		(img->texture[walldir]->width * tex_y * 4) + tex_x * 4];
	g = img->texture[walldir]->pixels[
		(img->texture[walldir]->width * tex_y * 4) + tex_x * 4 + 1];
	b = img->texture[walldir]->pixels[
		(img->texture[walldir]->width * tex_y * 4) + tex_x * 4 + 2];
	color = 0;
	color = ((int)(r << 24) | (int)(g << 16) | (int)(b << 8) | 0xFF);
	return (color);
}
