/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:05:01 by slakner           #+#    #+#             */
/*   Updated: 2023/03/11 20:05:37 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../MLX42/include/MLX42/MLX42.h"

# define SCREEN_X 			1080 //1700 //1920 //2560
# define SCREEN_Y			1080 //1440
# define EXIT_FAIL			1
# define EXIT_SUCCESS		0

typedef struct s_img_data
{
	uint32_t	screen_width;
	uint32_t	screen_height;
	// uint32_t	screen_half_x;
	// uint32_t	screen_half_y;
	double		player_x;	// player coordinates on map
	double		player_y;
	int			*map;
	uint32_t	map_x;	// map dimensions
	uint32_t	map_y;
	double		cam_p_x; // camera plane coordinates
	double		cam_p_y; 
	double		dir_x;	// direction vector coordinates
	double		dir_y;	
	// mlx_t		*mlx;
}	t_img_data;

typedef struct s_dpoint
{
	double x;
	double y;
}	t_dpoint;

t_img_data	init_img_data(); //(mlx_t* mlx);
void		draw_image(mlx_image_t *image, t_img_data *img_data);
void		draw_column(mlx_image_t *image, t_img_data *data, int x, double cam_x);//, double ray_angle);

#endif