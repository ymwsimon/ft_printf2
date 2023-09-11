/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_gen_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:37 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:37 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	g_table[] = "0123456789abcdef";

size_t	ft_int_length(long int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i = 2;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_uint_length(unsigned long int n, int base)
{
	size_t	i;

	i = 1;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_itoa(int n)
{
	size_t	i;
	int		sign;
	char	*res;

	i = ft_int_length(n);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		res[0] = '-';
	}
	if (!n)
		res = ft_strncpy(res, "0", 2);
	while (n)
	{
		res[i - 1] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return ((int)i);
}

int	ft_utoa(unsigned long int n, int trim, int base, int toupper)
{
	size_t	i;
	char	*res;

	if (trim)
		n = (unsigned int)n;
	i = ft_uint_length(n, base);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	if (!n)
		res = ft_strncpy(res, "0", 2);
	while (n)
	{
		res[i - 1] = g_table[n % base];
		n /= base;
		i--;
	}
	if (toupper)
		ft_strtoupper(res);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return ((int)i);
}

int	ft_ctoa(int c)
{
	char	n;

	n = (char)c;
	write(1, &n, 1);
	return (1);
}
