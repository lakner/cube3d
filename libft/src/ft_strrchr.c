/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:34:09 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 08:12:01 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s + ft_strlen((char *)s);
	while (*p != (unsigned char)c)
	{
		if (p == (char *)s)
			return (NULL);
		p--;
	}
	return (p);
}
