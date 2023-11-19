/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:49 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/19 21:15:17 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || \
		c == '\t' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (nptr && ft_isspace(*nptr))
		nptr++;
	if (nptr && *nptr == '-')
		sign = -1;
	if (nptr && (*nptr == '+' || *nptr == '-'))
		nptr++;
	while (nptr && *nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] && ((char)c) != s[i])
		i++;
	if (s[i])
		return (s + i);
	return (0);
}

void	init_flag(t_flag *f)
{
	if (f)
	{
		f->sharp = 0;
		f->left = 0;
		f->zero = 0;
		f->space = 0;
		f->plus = 0;
		f->minlen = 0;
		f->maxlen = ((unsigned int)-1) >> 1;
	}
}

t_flag	parse_flag(char *str)
{
	t_flag	res;
	int		i;

	init_flag(&res);
	i = 0;
	while (str && str[i] && !ft_strchr("cidpsuxX%123456789.", str[i]))
	{
		if (str[i] == '#')
			res.sharp = 1;
		if (str[i] == '-')
			res.left = 1;
		if (str[i] == '0')
			res.zero = 1;
		if (str[i] == ' ')
			res.space = 1;
		if (str[i] == '+')
			res.plus = 1;
		i++;
	}
	if (str[i] >= '1' && str[i] <= '9')
	{
		res.minlen = ft_atoi(str + i);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '.')
	{	
		i++;
		if (str[i] >= '1' && str[i] <= '9')
			res.maxlen = ft_atoi(str + i);
	}
	return (res);
}

int	ft_print_pattern(char *t, va_list ap)
{
	int		i;
	t_flag	s;

	s = parse_flag(t);
	printf("sharp=%d zero=%d left=%d min=%d max=%d plus=%d space=%d\n", s.sharp, s.zero, s.left, s.minlen, s.maxlen, s.plus, s.space);
	i = 0;
	while (t[i] && !ft_strchr("cidpsuxX%", t[i]))
		i++;
	if (t[i] == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	else if (t[i] == 'i' || t[i] == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (t[i] == 'p')
		return (ft_adrtoa(va_arg(ap, void *)));
	else if (t[i] == 's')
		return (ft_stoa(va_arg(ap, char *)));
	else if (t[i] == 'u')
		return (ft_utoa((unsigned int)va_arg(ap, int), 10, 0));
	else if (t[i] == 'x')
		return (ft_utoa((unsigned int)va_arg(ap, int), 16, 0));
	else if (t[i] == 'X')
		return (ft_utoa((unsigned int)va_arg(ap, int), 16, 1));
	else if (t[i] == '%')
		return (ft_ctoa('%'));
	return (0);
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
			{	
				res += ft_print_pattern((char *)fmt + 1, ap);
				fmt++;
			}
			while (*fmt && !ft_strchr("cidpsuxX%", *fmt))
				fmt++;
		}
		else
			res += ft_ctoa(*fmt);
		fmt++;
	}
	va_end(ap);
	return (res);
}
