/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:00 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 04:09:17 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

struct s_map_list
{
	char				*line;
	struct s_map_list	*next;
};

struct s_data
{
	int					width;
	int					height;
	int					map_fd;
	int					no_fd;
	int					so_fd;
	int					we_fd;
	int					ea_fd;
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
