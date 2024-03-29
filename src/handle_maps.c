/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:09:48 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/09 16:16:37 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	handle_maps(struct s_data *data)
{
	data->map = create_map_array(data);
	if (check_map(data->map, data->height, data->width) == false)
		raise_error(MAP_OPEN);
	data->map_int = map_to_int_array(data);
	if (data->height == 0 && data->width == 0)
		raise_error(MAPFILE_NO_MAP);
	if (data->player_s == false)
		raise_error(MAP_NO_PLAYER);
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
	**map_to_int_array(struct s_data *data)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = (int **) malloc(data->height * sizeof(int *));
	i = 0;
	while (i < data->height)
	{
		int_map[i] = (int *) malloc(data->width * sizeof(int));
	j = -1;
		while (++j < data->width)
		{
			if (data->map[i][j] == ' ')
				int_map[i][j] = 2;
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
					|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				set_player_position(data, int_map, i, j);
			else if (data->map[i][j] == '1' || data->map[i][j] == '0')
				int_map[i][j] = data->map[i][j] - '0';
			else
				raise_error(MAP_INV_CHAR);
		}
		i++;
	}
	return (int_map);
}

void
	set_player_position(struct s_data *data, int **int_map, int i, int j)
{
	if (data->player_s == true)
		raise_error(MAP_TOO_MANY_P);
	data->player_x = j;
	data->player_y = i;
	data->player_o = data->map[i][j];
	data->player_s = true;
	int_map[i][j] = 0;
}
