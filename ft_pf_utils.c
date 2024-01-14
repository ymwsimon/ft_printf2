/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:46 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/14 00:58:04 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_utoa(unsigned long int n, int base, int toupper)
{
	size_t	i;
	char	*res;
	char	*table;

	table = "0123456789abcdef";
	if (toupper)
		table = "0123456789ABCDEF";
	i = ft_uint_length(n, base);
	res = malloc(sizeof(char) * (i + 1));
	if (res)
		res[i] = 0;
	if (res && !n)
		res[0] = '0';
	while (res && n)
	{
		res[i - 1] = table[n % base];
		n /= base;
		i--;
	}
	return (res);
}

char	*join_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

char	*gen_pad(char c, size_t n)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (res && i < n)
	{
		res[i] = c;
		i++;
	}
	if (res)
		res[i] = 0;
	return (res);
}

int	print_len_free(char *s)
{
	int	res;

	res = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (res);
}
