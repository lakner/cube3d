/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:52:51 by slakner           #+#    #+#             */
/*   Updated: 2023/03/30 20:36:15 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "dda.h"
#include <math.h>
#include <stdio.h>

// ****** double	dda_walldist(t_img_data *data, t_dpoint ray_dir) ******
// DDA: Digital Differential Analysis
// Checks the map's "grid" lines for walls and intersections with
// the ray
// delta_side: portion of the ray pointing from one grid line to the next,
//				as a vector.
//				x component: between vertical lines
//				y componont: between horizontal lines
// dist_side:	ray vector from player position to a grid line
// map_sq:		square of the map corresponding to the player position

double	dda_walldist(t_img_data *data, t_column *col)
{
	t_ipoint	map_sq;

	map_sq.x = data->player.x;
	map_sq.y = data->player.y;
	col->delta_side.x = fabs(1.0 / col->ray_dir.x);
	col->delta_side.y = fabs(1.0 / col->ray_dir.y);
	col->dist_side = dist_to_grid_line(data, map_sq, col);
	return (dist_to_next_wall(data, map_sq, col));
}

// calculates the distance from between grid lines 
// (both vertical and horizontal) along the direction
// vector.

t_dpoint	dist_to_grid_line(t_img_data *data, t_ipoint map_sq, t_column *col)
{
	t_dpoint	dist_to_grid;

	if (col->ray_dir.x < 0)
		dist_to_grid.x = (data->player.x - map_sq.x) * col->delta_side.x;
	else
		dist_to_grid.x = (map_sq.x + 1.0 - data->player.x) * col->delta_side.x;
	if (col->ray_dir.y < 0)
		dist_to_grid.y = (data->player.y - map_sq.y) * col->delta_side.y;
	else
		dist_to_grid.y = (map_sq.y + 1.0 - data->player.y) * col->delta_side.y;
	return (dist_to_grid);
}

double	dist_to_next_wall(t_img_data *data, t_ipoint map_sq, t_column *col)
{
	while (1)
	{
		if (col->dist_side.x < col->dist_side.y)
		{
			col->dist_side.x += col->delta_side.x;
			map_sq.x += stepdir(col->ray_dir).x;
			if (data->map[map_sq.y][map_sq.x] > 0)
				return (wall_found(col, NS));
		}
		else
		{
			col->dist_side.y += col->delta_side.y;
			map_sq.y += stepdir(col->ray_dir).y;
			if (data->map[map_sq.y][map_sq.x] > 0)
				return (wall_found(col, EW));
		}
	}
}

t_ipoint	stepdir(t_dpoint ray_dir)
{
	t_ipoint	step_dir;

	if (ray_dir.x < 0)
		step_dir.x = -1;
	else
		step_dir.x = 1;
	if (ray_dir.y < 0)
		step_dir.y = -1;
	else
		step_dir.y = 1;
	return (step_dir);
}

double	wall_found(t_column *col, int walltype)
{
	if (walltype == 0)
	{
		if (col->ray_dir.y >= 0)
			col->walldir = EAST;
		else
			col->walldir = WEST;
		return (col->dist_side.y - col->delta_side.y);
	}
	else
	{
		if (col->ray_dir.x >= 0)
			col->walldir = NORTH;
		else
			col->walldir = SOUTH;
		return (col->dist_side.x - col->delta_side.x);
	}
}
