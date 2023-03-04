/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:44:43 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 20:46:10 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		len_s;
	char		*buf;
	const char	*ptr;

	len_s = ft_strlen(s);
	if (len_s < start)
		start = len_s;
	s += start;
	ptr = s;
	while (*ptr && len--)
		ptr++;
	len = ptr - s;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	ft_memcpy(buf, s, len);
	buf[len] = 0;
	return (buf);
}
