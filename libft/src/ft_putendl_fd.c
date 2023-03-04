/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:02:07 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 13:09:06 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd > 0 && s)
	{
		i = -1;
		while (s[++i])
			write(fd, &s[i], 1);
		write(fd, "\n", 1);
	}
}
