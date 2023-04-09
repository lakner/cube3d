/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:14:14 by slakner           #+#    #+#             */
/*   Updated: 2023/04/09 19:26:53 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "cub3d.h"
#include "draw_pixel_col.h"
#include "dda.h"

void	draw_pixel_col(mlx_image_t *image, t_img_data *data, int x)
{
	t_column	px_col;
	int			y;

	px_col = init_pxl_col(data, x);
	y = 0;
	draw_sky(image, &px_col, x, &y);
	draw_wall(image, data, &px_col, &y);
	while (y < SCREEN_Y)
	{
		mlx_put_pixel(image, x, y, data->ground_color);
		y++;
	}
}

t_column	init_pxl_col(t_img_data *data, int x)
{
	t_column	col;
	double		cam_x;

	cam_x = (double)(2 * x / (double) SCREEN_X) - 1;
	col.px_x = x;
	col.ray_dir.x = (double) data->dir.x + data->cam_p.x * cam_x;
	col.ray_dir.y = (double) data->dir.y + data->cam_p.y * cam_x;
	col.walldist = dda_walldist(data, &col);
	col.line_height = SCREEN_Y / col.walldist;
	col.sky_color = data->sky_color;
	col.ground_color = data->ground_color;
	col.draw_start = (-col.line_height / 2) + (SCREEN_Y / 2);
	if (col.draw_start < 0)
		col.draw_start = 0;
	col.draw_end = (col.line_height / 2) + (SCREEN_Y / 2);
	col.step = (double) data->texture[col.walldir]->height / col.line_height;
	if (col.draw_end >= SCREEN_Y)
		col.draw_end = SCREEN_Y - 1;
	return (col);
}

void	draw_sky(mlx_image_t *image, t_column *col, int x, int *y)
{
	while (*y < col->draw_start)
	{
		mlx_put_pixel(image, x, *y, col->sky_color);
		(*y)++;
	}
}

void	draw_wall(mlx_image_t *img, t_img_data *data, t_column *col, int *y)
{
	uint32_t	color;
	int			tex_x;
	double		tex_y;

	tex_y = (col->draw_start - SCREEN_Y / 2 + col->line_height / 2) * col->step;
	tex_x = calc_tex_x(data, col);
	while (*y < col->draw_end)
	{
		tex_y += col->step;
		color = get_texture_color(data, tex_y, tex_x, col->walldir);
		mlx_put_pixel(img, col->px_x, *y, color);
		(*y)++;
	}
}

int	calc_tex_x(t_img_data *data, t_column *col)
{
	double	wall_x;
	int		tex_x;

	if (col->walldir == NORTH || col->walldir == SOUTH)
	{
		wall_x = (double)data->player.x + col->walldist * col->ray_dir.x;
		wall_x -= floor(wall_x);
		tex_x = (wall_x * (double) data->texture[col->walldir]->width);
		if (col->walldir == SOUTH)
			tex_x = data->texture[col->walldir]->width - tex_x - 1;
	}
	else
	{
		wall_x = (double)data->player.y + col->walldist * col->ray_dir.y;
		wall_x -= floor(wall_x);
		tex_x = (wall_x * (double)data->texture[col->walldir]->width);
		if (col->walldir == WEST)
			tex_x = data->texture[col->walldir]->width - tex_x - 1;
	}
	return (tex_x);
}
