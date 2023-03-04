/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:18:34 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 20:17:00 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (++i < len)
		buf[i] = s[i];
	buf[i] = 0;
	return (buf);
}
