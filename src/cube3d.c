/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:04:40 by slakner           #+#    #+#             */
/*   Updated: 2023/03/11 20:09:51 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cube3d.h"
#include "../libft/include/libft.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	mlx_t* mlx;
	mlx_image_t* image;
	t_img_data img_data;

	if (!(mlx = mlx_init(SCREEN_X, SCREEN_Y, "CUBE3D", 1)))
	{
		printf("Mlx error: %d\n", mlx_errno);
		return(EXIT_FAIL);
	}
	if (!(image = mlx_new_image(mlx, SCREEN_X, SCREEN_Y)))
	{
		mlx_close_window(mlx);
		printf("Mlx error: %d\n", mlx_errno);
		return(EXIT_FAIL);
	}
	img_data = init_img_data(mlx);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		printf("Mlx error: %d\n", mlx_errno);
		return(EXIT_FAIL);
	}
	//mlx_loop_hook(mlx, draw_image, (void*) &imgdata);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	draw_image(image, &img_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}

t_img_data	init_img_data()//(mlx_t* mlx)
{
	t_img_data	img_data;
	
	// const int	map[10][10]
	// 	= {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
	// 		{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
	// 		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	// 		{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	// };
	// const int map[5][5]
	// 	= {{1, 1, 1, 1, 1},
	// 		{1, 0, 0, 1, 1},
	// 		{1, 0, 0, 0, 1},
	// 		{1, 0, 0, 0, 1},
	// 		{1, 1, 1, 1, 1}
	// 		};

	#define mapWidth 24
#define mapHeight 24

int map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

	img_data.screen_width = SCREEN_X;
	img_data.screen_height = SCREEN_Y;
	img_data.map_x = 24;
	img_data.map_y = 24;
	img_data.player_x = 22;
	img_data.player_y = 12;
	img_data.cam_p_x = 0;
	img_data.cam_p_y = 0.66;
	img_data.dir_x = -1;
	img_data.dir_y = 0;
	img_data.map = malloc(img_data.map_x * img_data.map_y * sizeof(int));
	printf("%d %d %f %f\n",img_data.map_x, img_data.map_y, img_data.player_x, img_data.player_y);
	ft_memcpy(img_data.map, map, img_data.map_x * img_data.map_y * sizeof(int));
	
	printf("%d %d %f %f\n",img_data.map_x, img_data.map_y, img_data.player_x, img_data.player_y);
	// img_data.mlx = mlx;
	return(img_data);
}


//cam_x:	coordinate in camera space: width of the screen
//			scaled to range -1...1, with 0 at the center of the screen
void draw_image(mlx_image_t *image, t_img_data *img_data)
{
	double		cam_x;
	uint32_t	x;
	x = 0;
	while (x < img_data->screen_width - 1)
	{
		cam_x = (2 * x / (double) img_data->screen_width) - 1;
		// cam_x calculations look okay
		// printf("cam_x: %f\n", cam_x);
		draw_column(image, img_data, x, cam_x);
		x++;
	}
}


//	calculates the direction vector in 'camera space'
//	scaled between -1 and 1, with 0 the x coordinate
//	at the center of the screen
t_dpoint	rayDir(t_img_data *data, double cam_x)
{
	t_dpoint	ray_dir;

	ray_dir.x = data->dir_x + data->cam_p_x * cam_x;
	ray_dir.y = data->dir_y + data->cam_p_y * cam_x;
	return (ray_dir);
}


// DDA: Digital Differential Analysis
// Checks the map's "grid" lines for walls and intersections with
// the ray
// t_dpoint	DDA_delta_dist(t_img_data *data, t_dpoint ray_dir)
// {
// 	t_dpoint	delta_dist;
	
// }

// delta_side: length of a ray portion between two grid lines.
//				x component: between vertical lines
//				y componont: between horizontal lines

double	DDA_wallfinder(t_img_data *data, t_dpoint ray_dir)
{

	int	map_x = data->player_x;	// square of the map that the ray is in
	int map_y = data->player_y;
	t_dpoint	dist_side;		// x component of var: distance from player to point where ray intersects vertical grid line
								// y component of var: distance from player to point where ray intersects horizontal grid line
	t_dpoint	delta_side;

	delta_side.x = 0;
	delta_side.y = 0;
	printf("map x,y (%d, %d)\n", map_x, map_y);
	// if (ray_dir.x == 0)
	// 	delta_side.x = 1e30;
	// else
		delta_side.x = fabs(1 / ray_dir.x);

	// if (ray_dir.y == 0)
	// 	delta_side.y = 1e30;
	// else
		delta_side.y = fabs(1 / ray_dir.y);
	//double real_wall_dist;

	//printf("map_x %d, map_y %d\n", map_x, map_y);

	// direction to check - either -1 or +1
	int step_x;
	int step_y;

	if (ray_dir.x < 0)
	{
		step_x = -1;
		dist_side.x = (data->player_x - map_x) * delta_side.x;
	}
	else
	{
		step_x = 1;
		dist_side.x = (map_x + 1.0 - data->player_x) * delta_side.x;
	}
	if (ray_dir.y < 0)
	{
		step_y = -1;
		dist_side.y = (data->player_y - map_y) * delta_side.y;
	}
	else
	{
		step_y = 1;
		dist_side.y = (map_y + 1.0 - data->player_y) * delta_side.y;
	}

	//printf("stepx: %d, stepy: %d\n", step_x, step_y);

	// was a wall found?
	int wall_found = 0;

	int walldir;
	//perform DDA
	while (!wall_found)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (dist_side.x < dist_side.y)
		{
			dist_side.x += delta_side.x;
			map_x += step_x;
			walldir = 0;
		}
		else
		{
			dist_side.y += delta_side.y;
			map_y += step_y;
			walldir = 1;
		}
		printf("dist (%f, %f), delta (%f, %f)\n", dist_side.x, dist_side.y, delta_side.x, delta_side.y);
		//Check if ray has hit a wall
		if (data->map[(data->map_x * map_y) + map_x] > 0) 
			wall_found = 1;
		// printf("iter %d, map square(%d, %d)\n", i, map_x, map_y);
	}
	if (walldir == 0)
		return (dist_side.x - delta_side.x);
	else
		return(dist_side.y - delta_side.y);
}

void	draw_column(mlx_image_t *image, t_img_data *data, int x, double cam_x)// double ray_angle)
{
	t_dpoint	ray_dir;
	double		no_fisheye_wall_dist;

	ray_dir = rayDir(data, cam_x);
	no_fisheye_wall_dist = DDA_wallfinder(data, ray_dir);
	printf("no_fisheye wall dist: %f\n", no_fisheye_wall_dist);
	int lineHeight = SCREEN_Y / no_fisheye_wall_dist;
	int draw_start = (-lineHeight / 2) + (SCREEN_Y / 2);
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = (lineHeight / 2) + (SCREEN_Y / 2);
	if (draw_end >= SCREEN_Y)
		draw_end = SCREEN_Y - 1;
	//printf("LineHeight %d, draw_start %d, draw_end %d, cam_p_d %f, player_pos: %f, %f  \n", lineHeight, draw_start, draw_end, cam_plane_dist, data->player_x, data->player_y);
	int y = 0;
	//int color = ((rand() %0xFF) << 24 | (rand() %0xFF) << 16 | (rand() %0xff << 8) | (rand() % 0xFF));
	while (y < draw_start)
	{
		mlx_put_pixel(image, x, y, 0x1e2f97ff);
		y++;
	}
	while (y < draw_end)
	{
		mlx_put_pixel(image, x, y, 0);
		y++;
	}
	while (y < SCREEN_Y)
	{
		mlx_put_pixel(image, x, y, 0x138510ff);
		y++;
	}
}
