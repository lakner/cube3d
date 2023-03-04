/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:19:23 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/15 01:32:11 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	lft_cnt_digits(int n)
{
	int		len;
	long	i;

	i = (long)n;
	if (n < 0)
		i = (long)n * -1;
	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else if (!n)
		return (1);
	else
		return (len + 1);
}

void
	lft_write_str(long n, int len, char *str)
{
	str[len] = 0;
	while (len)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len --;
	}
}

char
	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	len = lft_cnt_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n >= 0)
		lft_write_str(n, len, str);
	else
	{
		i = (long)n * -1;
		lft_write_str(i, len, str);
		str[0] = 45;
	}
	return (str);
}
