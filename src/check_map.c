/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:32:44 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/26 18:21:40 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	check_map(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (i == 0)
		{
			if (!check_first_line(map[i], width))
				return (false);
		}
		else if (i == height - 1)
		{
			if (!check_last_line(map[i], width))
				return (false);
		}
		else
		{
			if (!check_line(map[i - 1], map[i], map[i + 1], width))
				return (false);
		}
		i++;
	}
	return (true);
}

bool
	check_first_line(char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool
	check_last_line(char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool
	check_line(char *prev_line, char *line, char *next_line, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (line[j] == '0')
		{
			if (line[j + 1] == ' ' || line[j - 1] == ' '
				|| prev_line[j] == ' ' || next_line[j] == ' ')
				return (false);
		}
		j++;
	}
	return (true);
}
