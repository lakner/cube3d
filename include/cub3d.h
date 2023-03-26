/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:35:29 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 03:37:10 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

# include "../libft/include/libft.h"
# include "err_glossary.h"
# include "data.h"
# include "functions.h"
# include "print.h"


# include "../MLX42/include/MLX42/MLX42.h"

# define SCREEN_X 			1080 //1700 //1920 //2560
# define SCREEN_Y			1080 //1440
# define EXIT_FAIL			1
# define EXIT_SUCCESS		0

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define EW 0
# define NS 1

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_ipoint
{
	int	x;
	int	y;
}	t_ipoint;

// This struct stores the data for one 'column' of pixels drawn on the screen
typedef struct s_column
{
	double		walldist;
	int			walldir;
	double		step;
	t_dpoint	ray_dir;
	t_dpoint	dist_side;
	t_dpoint	delta_side;
	int			wall_type;
	double		px_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_column;

// int map_x, map_y: map dimensions
// t_dpoint player: player position
// t_dpoint cam_p: vector of the camera plane
// t_dpoint dir: direction vector

typedef struct s_img_data
{
	uint32_t		screen_width;
	uint32_t		screen_height;
	t_dpoint		player;
	double			move_speed;
	int				*map;
	mlx_texture_t	*texture[4];

	uint32_t		map_x;
	uint32_t		map_y;
	t_dpoint		cam_p;
	t_dpoint		dir;
	mlx_t			*mlx;
	mlx_image_t		*image;
}	t_img_data;

t_img_data	init_img_data(mlx_t *mlx, mlx_image_t *image);
void		draw_image(mlx_image_t *image, t_img_data *img_data);
int			win_close(t_img_data *img_data);
void		key_event(void *img_data);

uint32_t	get_texture_color(t_img_data *img,
				double tex_y, int tex_x, int walldir);

#endif