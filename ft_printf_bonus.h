/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:52 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/19 20:43:31 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flag
{
	int	sharp;
	int	zero;
	int	left;
	int	minlen;
	int	maxlen;
	int	plus;
	int	space;
}				t_flag;

size_t	ft_int_length(long int n);

size_t	ft_uint_length(unsigned long int n, int base);

int		ft_itoa(int n);

int		ft_utoa(unsigned long int n, int base, int toupper);

int		ft_ctoa(int c);

int		ft_adrtoa(void *adr);

int		ft_stoa(char *str);

size_t	ft_strlen(char *s);

char	*ft_strncpy(char *dest, const char *src, size_t n);

void	ft_putstr(char *s);

int		ft_print_pattern(char *t, va_list ap);

int		ft_printf(const char *fmt, ...);

#endif
