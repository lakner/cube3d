/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:00:33 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/08 20:07:15 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	check_id(struct s_data *data)
{
	if (data->no_fn == NULL || data->so_fn == NULL || data->we_fn == NULL
		|| data->ea_fn == NULL || data->f_colors == NULL
		|| data->c_colors == NULL)
		raise_error(MAPFILE_ID_NO_ID);
	return (true);
}

bool
	create_data(struct s_data *data, char *file_map)
{
	char				*line;
	struct s_map_list	*new;

	init_data(data, file_map);
	line = strip_newline(get_next_line(data->map_fd));
	while (line != NULL)
	{
		if (line_start_valid(line) == true)
			data_line_save(data, line);
		else if (line_map(data, line) == true && check_id(data) == true)
		{
			update_w_h(data, line);
			new = u_create_node(line);
			u_lst_add_back(&data->map_list, new);
		}
		else if (line_is_empty(data, line) == false)
			;
		else
			raise_error(MAPFILE_ERROR);
		free(line);
		line = strip_newline(get_next_line(data->map_fd));
	}
	handle_maps(data);
	return (true);
}

void
	init_data(struct s_data *data, char *file_map)
{
	data->map_fd = open(file_map, O_RDONLY);
	data->width = 0;
	data->height = 0;
	data->map_list = NULL;
	data->map_found = false;
	data->player_s = false;
	data->no_fn = NULL;
	data->so_fn = NULL;
	data->we_fn = NULL;
	data->ea_fn = NULL;
	data->f_colors = NULL;
	data->c_colors = NULL;
}

void
	update_w_h(struct s_data *data, char *line)
{
	data->height++;
	if (ft_strlen(line) > (size_t)data->width)
		data->width = ft_strlen(line);
}
