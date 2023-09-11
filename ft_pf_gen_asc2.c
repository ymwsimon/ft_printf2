/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_gen_asc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:43 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:43 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtoupper(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
		i++;
	}
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_adrtoa(void *adr)
{
	unsigned long int	n;
	int					i;

	if (!adr)
	{
		ft_putstr("(nil)");
		return (ft_strlen("(nil)"));
	}
	n = (unsigned long int) adr;
	ft_putstr("0x");
	i = 2;
	i += ft_utoa(n, 0, 16, 0);
	return ((int)i);
}

int	ft_validarg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
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
