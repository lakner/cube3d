/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:31:44 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 04:32:20 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// maybe create a garbage collecor to remove the shit before you exit
void
	raise_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

bool
	user_input(int argc, char **argv)
{
	if (argc == 1)
		raise_error(TOO_FEW_ARGS);
	if (argc > 2)
		raise_error(TOO_MANY_ARGS);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		raise_error(NOT_DOT_CUB);
	if (access(argv[1], R_OK) != 0)
		raise_error(MAP_NOT_FOUND);
	return (true);
}
