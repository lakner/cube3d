/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:50:17 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/11 02:08:16 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*
	strip_newline(char *line)
{
	int		len;
	char	*new;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		new = ft_strdup(line);
		free(line);
		return (new);
	}
	return (line);
}

bool
	line_start_valid(char *str)
{
	if ((str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A')
		|| (str[0] == 'F' && str[1] == ' ')
		|| (str[0] == 'C' && str[1] == ' '))
		return (true);
	return (false);
}

void
	data_line_save(struct s_data *data, char *str)
{
	data->tokens = ft_split(str, ' ');
	if (u_count_words(str, ' ') != 2)
		raise_error(MAPFILE_ID_ARGS);
	if (!u_strcmp(data->tokens[0], "NO") && texture_valid(data->tokens[1])
		&& data->no_fn == NULL)
		data->no_fn = ft_strncpy(data->tokens[1], ft_strlen(data->tokens[1]));
	else if (!u_strcmp(data->tokens[0], "SO") && texture_valid(data->tokens[1])
		&& data->so_fn == NULL)
		data->so_fn = ft_strncpy(data->tokens[1], ft_strlen(data->tokens[1]));
	else if (!u_strcmp(data->tokens[0], "WE") && texture_valid(data->tokens[1])
		&& data->we_fn == NULL)
		data->we_fn = ft_strncpy(data->tokens[1], ft_strlen(data->tokens[1]));
	else if (!u_strcmp(data->tokens[0], "EA") && texture_valid(data->tokens[1])
		&& data->ea_fn == NULL)
		data->ea_fn = ft_strncpy(data->tokens[1], ft_strlen(data->tokens[1]));
	else if (!u_strcmp(data->tokens[0], "F") && color_valid(data->tokens[1])
		&& data->f_colors == NULL)
		data->f_colors = scrap_colors(data->tokens[1]);
	else if (!u_strcmp(data->tokens[0], "C") && color_valid(data->tokens[1])
		&& data->c_colors == NULL)
		data->c_colors = scrap_colors(data->tokens[1]);
	else
		raise_error(MAPFILE_ID_VALUE);
	free_split(data->tokens);
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
	line_is_empty(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[ft_strlen(str)] = '\n';
	new[ft_strlen(str) + 1] = '\0';
	if (new[0] == '\n')
	{
		free(new);
		return (true);
	}
	free(new);
	return (false);
}
