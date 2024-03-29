/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:04:40 by slakner           #+#    #+#             */
/*   Updated: 2023/04/09 17:20:30 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw_pixel_col.h"

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

	tex_y = (int)(tex_pos) % (img->texture[walldir]->height - 1);
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
