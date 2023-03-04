/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:56:41 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 20:35:00 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*buf;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buf)
		return (NULL);
	ft_memcpy(buf, s1, len1);
	ft_memcpy(buf + len1, s2, len2);
	buf[len1 + len2] = 0;
	return (buf);
}
