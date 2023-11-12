/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:49 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/12 16:29:55 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pattern(char t, va_list ap)
{
	int	res;

	res = 0;
	if (t == 'c')
		res += ft_ctoa(va_arg(ap, int));
	else if (t == 'i' || t == 'd')
		res += ft_itoa(va_arg(ap, int));
	else if (t == 'p')
		res += ft_adrtoa(va_arg(ap, void *));
	else if (t == 's')
		res += ft_stoa(va_arg(ap, char *));
	else if (t == 'u')
		res += ft_utoa((unsigned int)va_arg(ap, int), 10, 0);
	else if (t == 'x')
		res += ft_utoa((unsigned int)va_arg(ap, int), 16, 0);
	else if (t == 'X')
		res += ft_utoa((unsigned int)va_arg(ap, int), 16, 1);
	else if (t == '%')
		res += ft_ctoa('%');
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, fmt);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
		{
			if (fmt[1])
				res += ft_print_pattern(fmt[1], ap);
			fmt++;
		}
		else
			res += ft_ctoa(*fmt);
		fmt++;
	}
	va_end(ap);
	return (res);
}
