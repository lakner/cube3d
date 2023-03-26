/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:30:38 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 17:19:30 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	color_valid(char *color)
{
	char	**rgb;
	int		i;

	i = 0;
	printf("The color is : %s\n", color);
	rgb = ft_split(color, ',');
	while (i < 3)
	{
		printf("The rgb is : %s\n", rgb[i]);
		if (rgb[i] == NULL || u_str_is_numeric(rgb[i]) == false)
		{
			free_split(rgb);
			return (false);
		}
		else if (ft_atoi(rgb[i]) < 0 && ft_atoi(rgb[i]) > 255)
		{
			free_split(rgb);
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
	// printf("The first color is : %d\n", ft_atoi(rgb[0]));
	colors[0] = ft_atoi(rgb[0]);
	colors[1] = ft_atoi(rgb[1]);
	colors[2] = ft_atoi(rgb[2]);
	colors[3] = '\0';
	return (colors);
}

int
	rgb_to_hex(unsigned char *colors)
{
	int	transparency;

	transparency = 255;
	return ((colors[0] << 24) + (colors[1]	<< 16) + (colors[2] << 8) + transparency);
}
