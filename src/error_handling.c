/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:31:44 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/09 03:08:22 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	raise_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

bool
	user_input(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		raise_error(TOO_FEW_ARGS);
	if (argc > 2)
		raise_error(TOO_MANY_ARGS);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		raise_error(NOT_DOT_CUB);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		raise_error(MAP_NOT_FOUND);
		return (false);
	}
	close(fd);
	return (true);
}
