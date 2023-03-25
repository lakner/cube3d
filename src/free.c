/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:06:41 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 05:06:43 by dcharala         ###   ########.fr       */
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
