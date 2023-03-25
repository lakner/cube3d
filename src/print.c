/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:23:21 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 03:23:23 by dcharala         ###   ########.fr       */
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
	printf("NO_fd: %d\n", data->no_fd);
	printf("SO_fd: %d\n", data->so_fd);
	printf("WE_fd: %d\n", data->we_fd);
	printf("EA_fd: %d\n", data->ea_fd);
	printf("F_colors: %d,%d,%d\n", data->f_colors[0], data->f_colors[1], data->f_colors[2]);
	printf("C_colors: %d,%d,%d\n", data->c_colors[0], data->c_colors[1], data->c_colors[2]);
	// printf("F_color: %lld\n", data->F_color);
	// printf("C_color: %lld\n", data->C_color);
	printf("map_found: %s\n", data->map_found ? "true" : "false");
	printf("The w and the h are : %d | %d\n", data->width, data->height);
	print_list(data->map_list);
	printf("The fucking map is : \n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%c ", data->map[i][j]);
		}
	printf("\n");
	}
	printf("The fucking int map is : \n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%d ", data->map_int[i][j]);
		}
		printf("\n");
	}
}