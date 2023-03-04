/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:05:01 by slakner           #+#    #+#             */
/*   Updated: 2023/03/04 16:09:22 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "MLX42/include/MLX42/MLX42.h"

# define SCREEN_X 			1080 //1700 //1920 //2560
# define SCREEN_Y			1080 //1440
# define EXIT_FAIL			1
# define EXIT_SUCCESS		0

typedef struct s_img_data
{
	uint32_t	screen_width;
	uint32_t	screen_height;
	uint32_t	screen_half_x;
	uint32_t	screen_half_y;
	int			render_delay;
	double		field_of_view_rad;
	double		field_of_view_half;
	uint32_t	player_x;
	uint32_t	player_y;
	double		player_angle_rad;
	double		rc_inc_angle;
	int			rc_prec;
	int			*map;
	mlx_t		*mlx;
}	t_img_data;

t_img_data	init_img_data(mlx_t* mlx);
void draw_image(mlx_image_t *image, t_img_data *img_data);
void		draw_column(mlx_image_t *image, t_img_data *data, int x);

#endif