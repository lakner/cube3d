/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:03:49 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 08:21:04 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	buf = (void *)malloc(nmemb * size);
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, nmemb * size);
	return (buf);
}
