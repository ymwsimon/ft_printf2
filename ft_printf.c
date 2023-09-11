/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:49 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:49 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpat(char t, va_list ap, int *res)
{
	if (t == 'c')
		*res += ft_ctoa(va_arg(ap, int));
	else if (t == 'i' || t == 'd')
		*res += ft_itoa(va_arg(ap, int));
	else if (t == 'p')
		*res += ft_adrtoa(va_arg(ap, void *));
	else if (t == 's')
		*res += ft_stoa(va_arg(ap, char *));
	else if (t == 'u')
		*res += ft_utoa(va_arg(ap, int), 1, 10, 0);
	else if (t == 'x')
		*res += ft_utoa(va_arg(ap, int), 1, 16, 0);
	else if (t == 'X')
		*res += ft_utoa(va_arg(ap, int), 1, 16, 1);
	else if (t == '%')
		*res += ft_percent();
}

int	ft_printuntilper(const char *fmt, int *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	tmp = 0;
	tmp = malloc(sizeof(char) * (i + 1));
	tmp = ft_strncpy(tmp, fmt, i);
	tmp[i] = 0;
	ft_putstr(tmp);
	*res += i;
	free(tmp);
	return (i);
}

int	ft_errorexit(va_list ap)
{
	va_end(ap);
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	res = 0;
	va_start(ap, fmt);
	while (fmt && *fmt)
	{
		i = ft_printuntilper(fmt, &res);
		if (fmt[i])
		{
			if (fmt[i + 1] && ft_validarg(fmt[i + 1]))
				ft_printpat(fmt[i + 1], ap, &res);
			else
				return (ft_errorexit(ap));
			fmt += 2;
		}
		fmt += i;
	}
	va_end(ap);
	return (res);
}
