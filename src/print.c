/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:23:21 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/26 18:32:52 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	print_list(struct s_map_list* head)
{
	struct s_map_list* current = head;
	while (current != NULL)
	{
		printf("The line is %s\n", current->line);
		current = current->next;
	}
}

void
	print_s_data(struct s_data* data)
{
	printf("map_fd: %d\n", data->map_fd);
	printf("NO_fd: %s\n", data->no_fn);
	printf("SO_fd: %s\n", data->so_fn);
	printf("WE_fd: %s\n", data->we_fn);
	printf("EA_fd: %s\n", data->ea_fn);
	printf("F_colors: %d,%d,%d\n", data->f_colors[0], data->f_colors[1], data->f_colors[2]);
	printf("C_colors: %d,%d,%d\n", data->c_colors[0], data->c_colors[1], data->c_colors[2]);
	printf("The f and c hex colors are: %x and %x\n", rgb_to_hex((unsigned char *)data->f_colors), rgb_to_hex((unsigned char *)data->c_colors));
	// printf("F_color: %lld\n", data->F_color);
	// printf("C_color: %lld\n", data->C_color);
	printf("map_found: %s\n", data->map_found ? "true" : "false");
	printf("The w and the h are : %d | %d\n", data->width, data->height);
	print_list(data->map_list);
	printf("The map is : \n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%c ", data->map[i][j]);
		}
	printf("\n");
	}
	printf("The int map is : \n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%d ", data->map_int[i][j]);
		}
		printf("\n");
	}
	printf("The player's positon is x:%d, y:%d\n", data->player_x, data->player_y);
}
