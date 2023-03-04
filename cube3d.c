/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:04:40 by slakner           #+#    #+#             */
/*   Updated: 2023/03/04 16:12:45 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cube3d.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	mlx_t* mlx;
	mlx_image_t* image;
	t_img_data img_data;

	if (!(mlx = mlx_init(SCREEN_X, SCREEN_Y, "CUBE3D", true)))
	{
		printf("Mlx error: %d\n", mlx_errno);
		return(EXIT_FAIL);
	}
	if (!(image = mlx_new_image(mlx, SCREEN_X, SCREEN_Y)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
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

t_img_data	init_img_data(mlx_t* mlx)
{
	t_img_data	img_data;
	const int	map[10][10]
		= {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
			{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
			{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
			{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	img_data.screen_width = SCREEN_X;
	img_data.screen_height = SCREEN_Y;
	img_data.screen_half_x = SCREEN_X/2;
	img_data.screen_half_y = SCREEN_Y/2;
	img_data.render_delay = 30;
	img_data.field_of_view_rad = 60;
	img_data.field_of_view_half = img_data.field_of_view_rad/2;
	img_data.player_x = img_data.screen_half_x;
	img_data.player_y = img_data.screen_half_y;
	img_data.player_angle_rad = 90;
	img_data.rc_inc_angle = img_data.field_of_view_rad / SCREEN_X;
	img_data.rc_prec = 64;
	img_data.map = malloc(100 * sizeof(int));
	ft_memcpy(img_data.map, map, 100);
	img_data.mlx = mlx;
	return(img_data);
}

void draw_image(mlx_image_t *image, t_img_data *img_data)
{
	uint32_t	x;

	x = 0;
	while (x < img_data->screen_width - 1)
	{
		draw_column(image, img_data, x);
		x++;
	}
}

void draw_column(mlx_image_t *image, t_img_data *data, int x)
{
	uint32_t	y;
	// (void) x;
	// (void) image;
	uint32_t color;
	
	color = ((rand() %0xFF) << 24 | (rand() %0xFF) << 16 | (rand() %0xff << 8) | (rand() % 0xFF));
	y = 0;

	while (y < data->screen_height - 1)
	{
		mlx_put_pixel(image, x, y, color);
		//mlx_put_pixel(image, x, y, 0xFFFF00);
		y++;
	}
}