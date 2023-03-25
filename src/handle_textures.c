/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:30:06 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 06:30:22 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	texture_valid(char *str)
{
	if (str != NULL && access(str, F_OK) != -1)
		return (true);
	return (false);
}
