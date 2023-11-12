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

int	ft_utoa(unsigned long int n, int base, int toupper)
{
	size_t	i;
	char	*res;
	char	table[17];

	ft_strncpy(table, "0123456789abcdef", 17);
	if (toupper)
		ft_strncpy(table, "0123456789ABCDEF", 17);
	i = ft_uint_length(n, base);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	if (!n)
		res = ft_strncpy(res, "0", 2);
	while (n)
	{
		res[i - 1] = table[n % base];
		n /= base;
		i--;
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}

int	ft_ctoa(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_adrtoa(void *adr)
{
	int	i;

	if (!adr)
	{
		ft_putstr("(nil)");
		return (ft_strlen("(nil)"));
	}
	ft_putstr("0x");
	i = 2;
	i += ft_utoa((unsigned long int) adr, 16, 0);
	return (i);
}

int	ft_stoa(char *str)
{
	if (str)
	{
		ft_putstr(str);
		return ((int)ft_strlen(str));
	}
	ft_putstr("(null)");
	return ((int)ft_strlen("(null)"));
}	
