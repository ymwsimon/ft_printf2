/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:34:49 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/14 00:56:39 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (res && s1 && *s1)
		res[i++] = *s1++;
	while (res && s2 && *s2)
		res[i++] = *s2++;
	if (res)
		res[i] = 0;
	return (res);
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
	return (NULL);
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
	if (res)
		res[i] = 0;
	sign = 1 * (n >= 0) + -1 * (n < 0);
	if (res)
		res[0] = '0' * (n == 0) + '-' * (n < 0);
	while (res && n)
	{
		res[i - 1] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	return (res);
}
