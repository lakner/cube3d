/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:05:01 by slakner           #+#    #+#             */
/*   Updated: 2023/03/12 19:59:41 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"

# define SCREEN_X 			1080 //1700 //1920 //2560
# define SCREEN_Y			1080 //1440
# define EXIT_FAIL			1
# define EXIT_SUCCESS		0

typedef struct s_dpoint
{
	double x;
	double y;
}	t_dpoint;


typedef struct s_img_data
{
	uint32_t	screen_width;
	uint32_t	screen_height;
	// double		player_x;	// player coordinates on map
	// double		player_y;
	t_dpoint	player;
	double		move_speed;
	int			*map;
	uint32_t	map_x;	// map dimensions
	uint32_t	map_y;
	// double		cam_p_x; // camera plane coordinates
	// double		cam_p_y; 
	t_dpoint	cam_p;
	t_dpoint	dir;
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_img_data;

t_img_data	init_img_data(mlx_t* mlx, mlx_image_t *image);
void		draw_image(mlx_image_t *image, t_img_data *img_data);
void		draw_column(mlx_image_t *image, t_img_data *data, int x, double cam_x);//, double ray_angle);

int			win_close(t_img_data *img_data);
void		key_event(void *img_data);

#endif