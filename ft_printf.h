/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:52 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/25 18:59:12 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	int		sharp;
	int		zero;
	int		left;
	size_t	minlen;
	size_t	prec;
	int		has_prec;
	int		plus;
	int		space;
}				t_flag;

size_t	ft_uint_length(unsigned long int n, int base);

char	*ft_utoa(unsigned long int n, int base, int toupper);

int		ft_print_pattern(char *t, va_list ap);

int		ft_printf(const char *fmt, ...);

int		ft_printc(char c, t_flag *f);

int		ft_printi(int n, t_flag *f);

int		ft_printuh(unsigned int n, t_flag *f, char type);

char	*join_free(char *s1, char *s2);

int		ft_printp(void *p, t_flag *f);

int		ft_prints(char *str, t_flag *f);

char	*gen_pad(char c, size_t n);

int		print_len_free(char *s);

#endif
