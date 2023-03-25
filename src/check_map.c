/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:32:44 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 05:54:36 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	check_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (i == 0)
		{
			if (!check_first_line(map[i]))
				return (false);
		}
		else if (i == height - 1)
		{
			if (!check_last_line(map[i]))
				return (false);
		}
		else
		{
			if (!check_line(map[i - 1], map[i], map[i + 1]))
				return (false);
		}
		i++;
	}
	return (true);
}

bool
	check_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool
	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool
	check_line(char *prev_line, char *line, char *next_line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
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
