/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:27:22 by dcharala          #+#    #+#             */
/*   Updated: 2023/03/25 06:28:14 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool
	u_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == false)
			return (false);
	return (true);
}

int
	u_count_words(char *str, char delim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if ((str[i] != delim && str[i + 1] == delim)
			|| (str[i] != delim && str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

int
	u_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}
