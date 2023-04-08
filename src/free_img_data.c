/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:28:33 by stephanie.l       #+#    #+#             */
/*   Updated: 2023/04/08 19:42:15 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img_data(t_img_data *img)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(img->texture[i]);
		i ++;
	}
	mlx_delete_image(img->mlx, img->image);
}
