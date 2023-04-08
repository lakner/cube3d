/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:35:29 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/08 19:15:58 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <errno.h>

# include "../MLX42/include/MLX42/MLX42.h"

# include "../libft/include/libft.h"
# include "err_glossary.h"
# include "data.h"
# include "functions.h"
# include "print.h"

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

t_img_data	init_img_data(t_data *data, mlx_t *mlx, mlx_image_t *image);
void		draw_image(mlx_image_t *image, t_img_data *img_data);
int			win_close(t_img_data *img_data);
void		key_event(void *img_data);
void		leftright_key_hook(mlx_key_data_t keydata, void *param);

uint32_t	get_texture_color(t_img_data *img,
				double tex_y, int tex_x, int walldir);

#endif
