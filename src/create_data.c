
#include "cub3d.h"

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
		else if (line_map(data, line) == true)
		{
			update_w_h(data, line);
			new = create_node(line);
			cub_lst_add_back(&data->map_list, new);
		}
		else if (line_is_empty(data, line) == false)
			;
		else
			raise_error(MAP_ERROR);
		free(line);
		line = strip_newline(get_next_line(data->map_fd));
	}
		/* if (check_map(data->map_list, 0) == false) */
		/* 	raise_error(INVALID_MAP); */
	handle_maps(data);
	return (true);
}

void
	init_data(struct s_data *data, char *file_map)
{
	data->map_fd = open(file_map, O_RDONLY);
	data->width = 0;
	data->height = 0;
	data->map_list = NULL; // uninitialized causes SIGSEG on Linux
}
