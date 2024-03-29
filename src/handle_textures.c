/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:30:06 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/26 22:18:37 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	texture_valid(char *str)
{
	int	fd;

	if (str == NULL)
		return (false);
	if (ft_strncmp(str + ft_strlen(str) - 4, ".png", 4))
	{
		raise_error(TEXTURE_PNG);
		return (false);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
		{
			raise_error(TEXTURE_PERMISSION);
			return (false);
		}
		raise_error(TEXTURE_OPEN);
		return (false);
	}
	close(fd);
	return (true);
}
