/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:11:40 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/15 01:35:04 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	lft_parse_nbr(int n, int fd)
{
	int	r;

	r = n % 10;
	n = n / 10;
	if (n >= 10)
		lft_parse_nbr(n, fd);
	else
		if (n)
			ft_putchar_fd(n + 48, fd);
	ft_putchar_fd(r + 48, fd);
}

void
	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > 0)
		lft_parse_nbr(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd(45, fd);
		n *= -1;
		lft_parse_nbr(n, fd);
	}
	else
		ft_putchar_fd(48, fd);
}
