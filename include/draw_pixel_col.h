/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_col.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:16:25 by slakner           #+#    #+#             */
/*   Updated: 2023/03/26 16:46:22 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_PIXEL_COL_H
# define DRAW_PIXEL_COL_H
# include "cub3d.h"
# include "dda.h"

void		draw_pixel_col(mlx_image_t *image, t_img_data *data, int x);
t_column	init_pxl_col(t_img_data *data, int x);
void		draw_sky(mlx_image_t *image, t_column *col, int x, int *y);
void		draw_wall(mlx_image_t *img, t_img_data *data,
				t_column *col, int *y);
int			calc_tex_x(t_img_data *data, t_column *col);

#endif