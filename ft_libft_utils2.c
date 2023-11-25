/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:34:49 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/25 19:50:30 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res)
	{
		i = 0;
		while (s1 && *s1)
			res[i++] = *s1++;
		while (s2 && *s2)
			res[i++] = *s2++;
		res[i] = 0;
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (i + 1 < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (i < size)
			dst[i] = 0;
	}
	while (src && src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (s && !c)
		return ((char *)s);
	return (0);
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		sign;
	char	*res;

	i = 1 + 1 * (n < 0);
	sign = n;
	while (sign / 10)
	{
		sign /= 10;
		i++;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (res);
	res[i] = 0;
	sign = 1 * (n >= 0) + -1 * (n < 0);
	res[0] = '0' * (n == 0) + '-' * (n < 0);
	while (n)
	{
		res[i - 1] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	return (res);
}
