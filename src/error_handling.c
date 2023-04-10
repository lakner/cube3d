/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:31:44 by dcharala          #+#    #+#             */
/*   Updated: 2023/04/10 20:37:15 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	raise_error(char *err)
{
	printf("Error\n");
	write(2, err, ft_strlen(err));
	exit(1);
}

bool
	user_input(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		raise_error(TERM_TOO_FEW_ARGS);
	if (argc > 2)
		raise_error(TERM_TOO_MANY_ARGS);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		raise_error(MAPFILE_EXT);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		raise_error(MAPFILE_NOT_FOUND);
		return (false);
	}
	close(fd);
	return (true);
}
