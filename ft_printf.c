/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:49 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/14 01:00:13 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		f->prec = 0;
		f->has_prec = 0;
	}
}

void	parse_width_prec(char *str, t_flag *f)
{
	int	i;

	i = 0;
	if (str[i] >= '1' && str[i] <= '9')
	{
		f->minlen = ft_atoi(str + i);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '.')
	{	
		i++;
		f->has_prec = 1;
		f->prec = ft_atoi(str + i);
	}
}

void	parse_flag(char *str, t_flag *f)
{
	int		i;

	init_flag(f);
	i = 0;
	while (str && str[i] && !ft_strchr("cidpsuxX%123456789.", str[i]))
	{
		if (str[i] == '#')
			f->sharp = 1;
		if (str[i] == '-')
			f->left = 1;
		if (str[i] == '0')
			f->zero = 1;
		if (str[i] == ' ')
			f->space = 1;
		if (str[i] == '+')
			f->plus = 1;
		i++;
	}
	parse_width_prec(str + i, f);
}

int	ft_print_pattern(char *t, va_list ap)
{
	int		i;
	t_flag	f;

	parse_flag(t, &f);
	i = 0;
	while (t[i] && !ft_strchr("cidpsuxX%", t[i]))
		i++;
	if (t[i] == 'c')
		return (ft_printc(va_arg(ap, int), &f));
	else if (t[i] == 'i' || t[i] == 'd')
		return (ft_printi(va_arg(ap, int), &f));
	else if (t[i] == 'p')
		return (ft_printp(va_arg(ap, void *), &f));
	else if (t[i] == 's')
		return (ft_prints(va_arg(ap, char *), &f));
	else if (t[i] == 'u')
		return (ft_printuh((unsigned int)va_arg(ap, int), &f, 'u'));
	else if (t[i] == 'x')
		return (ft_printuh((unsigned int)va_arg(ap, int), &f, 'x'));
	else if (t[i] == 'X')
		return (ft_printuh((unsigned int)va_arg(ap, int), &f, 'X'));
	else if (t[i] == '%')
		return (ft_printc('%', NULL));
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
				res += ft_print_pattern((char *)++fmt, ap);
			while (*fmt && !ft_strchr("cidpsuxX%", *fmt))
				fmt++;
		}
		else
			res += ft_printc(*fmt, NULL);
		if (*fmt)
			fmt++;
	}
	va_end(ap);
	return (res);
}
