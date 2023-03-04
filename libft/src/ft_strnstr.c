/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:15:22 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 08:21:44 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = -1;
	while (++i < len && big[i])
	{
		j = -1;
		while (i + ++j < len && little[j] && big[i + j] == little[j])
			if (little[j + 1] == 0)
				return ((char *)&big[i]);
	}
	return (NULL);
}
