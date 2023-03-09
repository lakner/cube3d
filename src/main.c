/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:37:50 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/09 22:04:45 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    user_input()
{
    return (true);
}

void free_split(char **tokens)
{
    char **tmp = tokens;
    
    while (*tmp)
        free(*tmp++);
    free(tokens);
}

void    raise_error(char *err)
{
    write(2, err, ft_strlen(err));
    // maybe create a garbage collecor to remove the shit before you exit
    exit(1);
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

    // free split before you return false
    i = 0;
    rgb = ft_split(color, ',');
    while (i < 3)
    {
        if (rgb[i] == NULL || ft_str_is_numeric(rgb[i]) == false)
            return (false);
        else if (ft_atoi(rgb[i]) < 0 && ft_atoi(rgb[i]) > 255)
            return (false);
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

void    data_line_save(struct s_data *data, char *str)
{
    char    **tokens;

    tokens = ft_split(str, ' ');
    // add code to check weather or not the line doesn't contain more than 2 words
    // add code and change the ft_strncmp to ft_strcmp
    if (ft_strncmp(tokens[0], "NO", 2) && texture_valid(tokens[1]))
        data->NO_fd = open(tokens[1], O_RDONLY);
    else if (ft_strncmp(tokens[0], "SO", 2) && texture_valid(tokens[1]))
        data->SO_fd = open(tokens[1], O_RDONLY);
    else if (ft_strncmp(tokens[0], "WE", 2) && texture_valid(tokens[1]))
        data->WE_fd = open(tokens[1], O_RDONLY);
    else if (ft_strncmp(tokens[0], "EA", 2) && texture_valid(tokens[1]))
        data->EA_fd = open(tokens[1], O_RDONLY);
    else
        raise_error(TEXTURE_INVALID);
    if (ft_strncmp(tokens[0], "F", 1) && color_valid(tokens[1]))
        data->F_colors = scrap_colors(tokens[1]);
    else if (ft_strncmp(tokens[0], "C", 1) && color_valid(tokens[1]))
        data->C_colors = scrap_colors(tokens[1]);
    else
        raise_error(COLOR_INVALID);
    free_split(tokens);
}

bool    data_create(struct s_data *data, char *file_map)
{
    char    *line;

    data->map_fd = open(file_map, O_RDONLY);
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

    (void)argc;
    if (user_input() == true)
    {
        if (data_create(&data, argv[1]))
            draw();
        data_destroy(&data);
    }
    else
        raise_error(WRONG_INPUT);
}