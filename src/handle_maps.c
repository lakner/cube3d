/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:09:48 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 05:31:15 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	handle_maps(struct s_data *data)
{
	data->map = create_map_array(data);
	if (check_map(data->map, data->height) == false)
		raise_error(INVALID_MAP);
	data->map_int = map_to_int_array(data->map, data->height, data->width);
	print_s_data(data);
}

char**
	create_map_array(struct s_data *data)
{
	char	**map_array;
	int		i;

	map_array = (char **) malloc(data->height * sizeof(char *));
	i = 0;
	while (i < data->height)
	{
		map_array[i] = (char *) malloc(data->width * sizeof(char));
		ft_memset(map_array[i], ' ', data->width);
		i++;
	}
	fill_map_array(map_array, data);
	return (map_array);
}

void
	fill_map_array(char **map_array, struct s_data *data)
{
	int					row;
	int					col;
	int					line_len;
	struct s_map_list	*current;

	current = data->map_list;
	row = 0;
	while (current != NULL && row < data->height)
	{
		col = 0;
		line_len = ft_strlen(current->line);
		while (col < line_len && col < data->width)
		{
			map_array[row][col] = current->line[col];
			col++;
		}
		current = current->next;
		row++;
	}
}

int
	**map_to_int_array(char **map, int height, int width)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = (int **) malloc(height * sizeof(int *));
	i = 0;
	while (i < height)
	{
		int_map[i] = (int *) malloc(width * sizeof(int));
	j = 0;
		while (j < width)
		{
			if (map[i][j] == ' ')
				int_map[i][j] = 2;
			else if (map[i][j] == 'N')
				int_map[i][j] = 3;
			else
				int_map[i][j] = map[i][j] - '0';
			j++;
		}
		i++;
	}
	return (int_map);
}
