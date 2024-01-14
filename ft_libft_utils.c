/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:32:43 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/14 00:55:40 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	i = (n - 1) * (s < d);
	while (s && d && i < n)
	{
		d[i] = s[i];
		if (s > d)
			i++;
		else
			i--;
	}
	return (dest);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*t;

	i = 0;
	while (s && s[i])
		i++;
	t = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (t && s && s[++i])
		t[i] = s[i];
	if (t)
		t[i] = 0;
	return (t);
}
