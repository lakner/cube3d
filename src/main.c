/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:37:50 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/06 00:17:28 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	throw_mlx_err(void)
{
	printf("Mlx error: %d\n", mlx_errno);
	return (EXIT_FAIL);
}

int
	draw(t_data *data)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_img_data	img_data;

	mlx = mlx_init(SCREEN_X, SCREEN_Y, "CUBE3D", 1);
	if (!mlx)
		return (throw_mlx_err());
	image = mlx_new_image(mlx, SCREEN_X, SCREEN_Y);
	if (!image)
	{
		mlx_close_window(mlx);
		return (throw_mlx_err());
	}
	img_data = init_img_data(data, mlx, image);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		return (throw_mlx_err());
	}
	mlx_loop_hook(mlx, key_event, &img_data);
	draw_image(image, &img_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int
	main(int argc, char **argv)
{
	struct s_data	data;

	if (user_input(argc, argv) == true)
	{
		if (create_data(&data, argv[1]))
			draw(&data);
		data_destroy(&data);
	}
	printf("I m here\n");
	system("leaks cub3D");
}
