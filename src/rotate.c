/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:39:55 by slakner           #+#    #+#             */
/*   Updated: 2023/04/08 19:41:15 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
