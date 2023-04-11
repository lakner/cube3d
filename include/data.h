/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/09 16:18:03 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

struct s_map_list
{
	char				*line;
	struct s_map_list	*next;
};

typedef struct s_data
{
	int					player_x;
	int					player_y;
	char				player_o;
	bool				player_s;
	int					width;
	int					height;
	int					map_fd;
	char				*no_fn;
	char				*so_fn;
	char				*we_fn;
	char				*ea_fn;
	char				**tokens;
	unsigned char		*f_colors;
	unsigned char		*c_colors;
	long long			f_color;
	long long			c_color;
	bool				map_found;
	struct s_map_list	*map_list;
	char				**map;
	int					**map_int;
}	t_data;

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
	uint32_t	sky_color;
	uint32_t	ground_color;
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
	int				**map;
	mlx_texture_t	*texture[4];
	uint32_t		map_x;
	uint32_t		map_y;
	t_dpoint		cam_p;
	t_dpoint		dir;
	mlx_t			*mlx;
	mlx_image_t		*image;
	uint32_t		sky_color;
	uint32_t		ground_color;
}	t_img_data;

#endif
