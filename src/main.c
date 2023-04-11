/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:37:50 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/08 20:06:37 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	throw_mlx_err(void)
{
	printf("Mlx error: %d\n", mlx_errno);
	return (EXIT_FAIL);
}

void	init_mlx_hooks_loop(mlx_t *mlx, mlx_image_t *img, t_img_data *img_data)
{
	mlx_key_hook(mlx, leftright_key_hook, img_data);
	mlx_loop_hook(mlx, key_event, img_data);
	draw_image(img, img_data);
	mlx_loop(mlx);
}

int	draw(t_data *data)
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
	init_mlx_hooks_loop(mlx, image, &img_data);
	free_img_data(&img_data);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int
	main(int argc, char **argv)
{
	struct s_data	data;

	if (user_input(argc, argv) == true)
	{
		init_data(&data, argv[1]);
		if (create_data(&data))
			draw(&data);
		data_destroy(&data);
	}
}
