/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:50:17 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 04:54:35 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*
	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

bool
	line_start_valid(char *str)
{
	if (str[0] == 'N'
		|| str[0] == 'S'
		|| str[0] == 'W'
		|| str[0] == 'E'
		|| str[0] == 'F'
		|| str[0] == 'C')
		return (true);
	return (false);
}

void
	data_line_save(struct s_data *data, char *str)
{
	char	**tokens;

	tokens = ft_split(str, ' ');
	if (u_count_words(str, ' ') > 2)
		raise_error(TOO_MANY_ARGS_FOR_PATH);
	if (!u_strcmp(tokens[0], "NO") && texture_valid(tokens[1]))
		data->no_fd = open(tokens[1], O_RDONLY);
	else if (!u_strcmp(tokens[0], "SO") && texture_valid(tokens[1]))
		data->so_fd = open(tokens[1], O_RDONLY);
	else if (!u_strcmp(tokens[0], "WE") && texture_valid(tokens[1]))
		data->we_fd = open(tokens[1], O_RDONLY);
	else if (!u_strcmp(tokens[0], "EA") && texture_valid(tokens[1]))
		data->ea_fd = open(tokens[1], O_RDONLY);
	else if (!u_strcmp(tokens[0], "F") && color_valid(tokens[1]))
		data->f_colors = scrap_colors(tokens[1]);
	else if (!u_strcmp(tokens[0], "C") && color_valid(tokens[1]))
		data->c_colors = scrap_colors(tokens[1]);
	else
		raise_error(COLOR_INVALID);
	free_split(tokens);
}

bool
	line_map(struct s_data *data, char *str)
{
	if (str[0] == '1' || str[0] == ' ')
	{
		data->map_found = true;
		return (true);
	}
	return (false);
}

bool
	line_is_empty(struct s_data *data, char *str)
{
	if (data->map_found == true && str[0] == '\n')
		return (true);
	return (false);
}
