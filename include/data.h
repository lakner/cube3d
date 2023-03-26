/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakner <slakner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/26 18:26:49 by slakner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

struct s_map_list
{
	char				*line;
	struct s_map_list	*next;
};

typedef struct s_data
{
	int					width;
	int					height;
	int					map_fd;
	// int					no_fd;
	// int					so_fd;
	// int					we_fd;
	// int					ea_fd;
	char				*no_fn;
	char				*so_fn;
	char				*we_fn;
	char				*ea_fn;
	unsigned char		*f_colors;
	unsigned char		*c_colors;
	long long			f_color;
	long long			c_color;
	bool				map_found;
	struct s_map_list	*map_list;
	char				**map;
	int					**map_int;
}	t_data;

#endif
