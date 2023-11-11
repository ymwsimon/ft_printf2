/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:46 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/11 17:14:07 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest && src && src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest && i < n)
		dest[i++] = 0;
	return (dest);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
