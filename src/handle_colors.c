/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:30:38 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/08 20:11:51 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	color_valid(char *color)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = ft_split(color, ',');
	while (i < 3)
	{
		if (rgb[i] == NULL || u_str_is_numeric(rgb[i]) == false)
		{
			free_split(rgb);
			raise_error(COLOR_INVALID);
			return (false);
		}
		else if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			free_split(rgb);
			raise_error(COLOR_INVALID);
			return (false);
		}
		i++;
	}
	free_split(rgb);
	return (true);
}

unsigned char*
	scrap_colors(char *color)
{
	char			**rgb;
	unsigned char	*colors;

	rgb = ft_split(color, ',');
	colors = malloc(sizeof(char) * 4);
	colors[0] = ft_atoi(rgb[0]);
	colors[1] = ft_atoi(rgb[1]);
	colors[2] = ft_atoi(rgb[2]);
	colors[3] = '\0';
	free_split(rgb);
	return (colors);
}

int
	rgb_to_hex(unsigned char *colors)
{
	int	transparency;

	transparency = 255;
	return ((colors[0] << 24) + (colors[1] << 16) + (colors[2] << 8)
		+ transparency);
}
