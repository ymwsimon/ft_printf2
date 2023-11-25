/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:46 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/25 18:58:54 by mayeung          ###   ########.fr       */
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
	char	table[17];

	ft_strlcpy(table, "0123456789abcdef", 17);
	if (toupper)
		ft_strlcpy(table, "0123456789ABCDEF", 17);
	i = ft_uint_length(n, base);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	if (!n)
		res[0] = '0';
	while (n)
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
	if (!res)
		return (res);
	i = 0;
	while (i < n)
	{
		res[i] = c;
		i++;
	}
	res[i] = 0;
	return (res);
}

int	print_len_free(char *s)
{
	int	res;

	res = 0;
	res = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (res);
}
