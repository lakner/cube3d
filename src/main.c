/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:37:50 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/09 23:59:21 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raise_error(char *err)
{
    write(2, err, ft_strlen(err));
    // maybe create a garbage collecor to remove the shit before you exit
    exit(1);
}

// check on whether to return false at all
bool    user_input(int argc, char **argv)
{
	if (argc > 2)
	{
		raise_error(TOO_MANY_ARGS);
		return (false);
	}
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
    {
    	raise_error(NOT_DOT_CUB);
    	return (false);
    }
	return (true);
}

void free_split(char **tokens)
{
    char **tmp = tokens;
    
    while (*tmp)
        free(*tmp++);
    free(tokens);
}

bool    line_start_valid(struct s_data *data, char *str)
{
    if (str[0] == 'N'
        || str[0] == 'S'
        || str[0] == 'W'
        || str[0] == 'E'
        || str[0] == 'F'
        || str[0] == 'C')
        return (true);
    else if (str[0] == '1' || str[0] == ' ')
    {
        data->map_found = true;
        return (true);
    }
    return (false);
}

bool    line_is_empty(struct s_data *data, char *str)
{
    if (data->map_found == true && str[0] == '\n')
        return (true);
    return (false);
}

bool    texture_valid(char *str)
{
    if (str != NULL && access(str, R_OK) == true)
        return (true);
    return (false);
}

bool    ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == true)
			return (true);
	return (false);
}

bool    color_valid(char *color)
{
    char **rgb;
    int i;

    // free split before you return false - done
    i = 0;
    rgb = ft_split(color, ',');
    while (i < 3)
    {
        if (rgb[i] == NULL || ft_str_is_numeric(rgb[i]) == false)
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

char    *scrap_colors(char *color)
{
    char    **rgb;
    char    *colors;

    rgb = ft_split(color, ',');
    colors = malloc(sizeof(char) * 4);
    colors[0] = ft_atoi(rgb[0]);
    colors[1] = ft_atoi(rgb[1]);
    colors[2] = ft_atoi(rgb[2]);
    colors[3] = '\0';
    return (colors);
}

int
	cnt_words(char *str, char delim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if ((str[i] != delim && str[i + 1] == delim)
			|| (str[i] != delim && str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

int
	cub_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}

void    data_line_save(struct s_data *data, char *str)
{
    char    **tokens;

    tokens = ft_split(str, ' ');
    // add code to check weather or not the line doesn't contain more than 2 words - done
    if (cnt_words(str, ' ') > 2)
        raise_error(TOO_MANY_ARGS_FOR_PATH);
    // add code and change the ft_strncmp to ft_strcmp - done
    if (cub_strcmp(tokens[0], "NO") && texture_valid(tokens[1]))
        data->NO_fd = open(tokens[1], O_RDONLY);
    else if (cub_strcmp(tokens[0], "SO") && texture_valid(tokens[1]))
        data->SO_fd = open(tokens[1], O_RDONLY);
    else if (cub_strcmp(tokens[0], "WE") && texture_valid(tokens[1]))
        data->WE_fd = open(tokens[1], O_RDONLY);
    else if (cub_strcmp(tokens[0], "EA") && texture_valid(tokens[1]))
        data->EA_fd = open(tokens[1], O_RDONLY);
    else
        raise_error(TEXTURE_INVALID);
    if (cub_strcmp(tokens[0], "F") && color_valid(tokens[1]))
        data->F_colors = scrap_colors(tokens[1]);
    else if (cub_strcmp(tokens[0], "C") && color_valid(tokens[1]))
        data->C_colors = scrap_colors(tokens[1]);
    else
        raise_error(COLOR_INVALID);
    free_split(tokens);
}

bool    data_create(struct s_data *data, char *file_map)
{
    char    *line;

    data->map_fd = open(file_map, O_RDONLY);
    if (data->map_fd == -1)
    	raise_error(MAP_NOT_FOUND);
    line = get_next_line(data->map_fd);
    while (line != NULL)
    {
        if (line_start_valid(data, line) == true)
            data_line_save(data, line);
        else if (line_is_empty(data, line) == false)
            ;
        else
            raise_error(MAP_ERROR);
        free(line);
        line = get_next_line(data->map_fd);
    }
    return (true);
}

void    draw()
{

}

void    data_destroy(struct s_data *data)
{
    close(data->map_fd);
    // FREE THE COLORS
    // try to remove everthing alloced (map and the textures strings if allocated)
}



int main(int argc, char **argv)
{
    struct s_data   data;

    if (user_input(argc, argv) == true)
    {
        if (data_create(&data, argv[1]))
            draw();
        data_destroy(&data);
    }
    else
        raise_error(WRONG_INPUT);
}
