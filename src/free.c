/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:06:41 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/08 19:08:06 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	free_split(char **tokens)
{
	char	**tmp;

	tmp = tokens;
	while (*tmp)
		free(*tmp++);
	free(tokens);
}

void
	free_matrix_int(int	**map_int, int height)
{
	int i;

	i = 0;
	while(i < height)
	{
		free(map_int[i]);
		i++;
	}
	free(map_int);
}

void
	free_matrix(char	**map, int height)
{
	int i;

	i = 0;
	while(i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void free_linked_list(struct s_map_list* head)
{
    struct s_map_list* current = head;
    while (current != NULL) {
        struct s_map_list* temp = current;
        current = current->next;
        free(temp->line);
        free(temp);
    }
}

void
	data_destroy(struct s_data *data)
{
	close(data->map_fd);
	free(data->no_fn);
	free(data->so_fn);
	free(data->we_fn);
	free(data->ea_fn);
	free(data->f_colors);
	free(data->c_colors);
	free_matrix(data->map, data->height);
	free_matrix_int(data->map_int, data->height);
	free_linked_list(data->map_list);
}
