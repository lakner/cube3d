/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:58:20 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/15 19:34:37 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	pf_distribute_conversion(char specifier, va_list ap)
{
	int	nbytes;

	nbytes = 0;
	if (specifier == 'c')
		nbytes = pf_convert_chr(ap);
	else if (specifier == 's')
		nbytes = pf_convert_str(ap);
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		nbytes = pf_convert_nbr(ap, specifier);
	else if (specifier == 'x' || specifier == 'X')
		nbytes = pf_convert_hex(ap, specifier);
	else if (specifier == 'p')
		nbytes = pf_convert_ptr(ap);
	else
		nbytes = write(1, &specifier, 1);
	return (nbytes);
}

void
	pf_get_specifiers(va_list ap, char *fmt, int *nbytes)
{
	int		i;
	char	*specifiers;

	specifiers = "cspdiuxX%";
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			while (fmt[++i] && !ft_strchr(specifiers, fmt[i]))
				;
			if (!fmt[i])
				break ;
			*nbytes += pf_distribute_conversion(fmt[i], ap);
		}
		else
			*nbytes += write(1, &fmt[i], 1);
	}
}

int
	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		nbytes;

	nbytes = 0;
	va_start(ap, fmt);
	pf_get_specifiers(ap, (char *)fmt, &nbytes);
	va_end(ap);
	return (nbytes);
}
