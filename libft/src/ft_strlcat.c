/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:39:52 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 08:04:51 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size < dst_len)
		return (src_len + size);
	i = -1;
	while (dst_len + 1 + ++i < size && src[i] != 0)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
