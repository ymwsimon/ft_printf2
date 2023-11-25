/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_asc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:57:13 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/25 21:15:50 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c, t_flag *f)
{
	int		len;
	char	*pad;

	len = 1;
	pad = 0;
	if (f && f->minlen > 1)
		pad = gen_pad(' ', f->minlen - 1);
	if (f && !f->left)
		ft_putstr_fd(pad, 1);
	write(1, &c, 1);
	if (f && f->left)
		ft_putstr_fd(pad, 1);
	len += ft_strlen(pad);
	free(pad);
	return (len);
}

int	ft_printi(int n, t_flag *f)
{
	char	*iasc;

	iasc = ft_itoa(n);
	if (f && f->has_prec && !f->prec && !n)
		iasc[0] = 0;
	if (n < 0)
		ft_memmove(iasc, iasc + 1, ft_strlen(iasc));
	if (f && f->prec > ft_strlen(iasc))
		iasc = join_free(gen_pad('0', f->prec - ft_strlen(iasc)), iasc);
	else if (f && !f->left && f->zero && !f->has_prec && \
	f->minlen > (ft_strlen(iasc) + (1 * (n < 0 || f->plus || f->space))))
		iasc = join_free(gen_pad('0', f->minlen - (ft_strlen(iasc) + \
		1 * (n < 0 || f->plus || f->space))), iasc);
	if (f && n >= 0 && f->plus)
		iasc = join_free(ft_strdup("+"), iasc);
	else if (f && n >= 0 && !f->plus && f->space)
		iasc = join_free(ft_strdup(" "), iasc);
	if (f && n < 0)
		iasc = join_free(ft_strdup("-"), iasc);
	if (f && f->left && f->minlen > ft_strlen(iasc))
		iasc = join_free(iasc, gen_pad(' ', f->minlen - ft_strlen(iasc)));
	else if (f && !f->left && f->minlen > ft_strlen(iasc))
		iasc = join_free(gen_pad(' ', f->minlen - ft_strlen(iasc)), iasc);
	return (print_len_free(iasc));
}

int	ft_printuh(unsigned int n, t_flag *f, char type)
{
	char	*nasc;

	if (!n && f && f->has_prec && !f->prec)
		nasc = ft_strdup("");
	else if (type == 'x')
		nasc = ft_utoa(n, 16, 0);
	else if (type == 'X')
		nasc = ft_utoa(n, 16, 1);
	else
		nasc = ft_utoa(n, 10, 0);
	if (f && f->prec > ft_strlen(nasc))
		nasc = join_free(gen_pad('0', f->prec - ft_strlen(nasc)), nasc);
	if (f && ((f->minlen > (ft_strlen(nasc) + f->sharp * 2) && n) || \
	(f->minlen > ft_strlen(nasc) && !n)) && f->zero && !f->has_prec)
		nasc = join_free(gen_pad('0', \
		f->minlen - ((n != 0) * f->sharp * 2) - ft_strlen(nasc)), nasc);
	if (f && f->sharp && n && type == 'x')
		nasc = join_free(ft_strdup("0x"), nasc);
	else if (f && f->sharp && n && type == 'X')
		nasc = join_free(ft_strdup("0X"), nasc);
	if (f && f->minlen > ft_strlen(nasc) && f->left)
		nasc = join_free(nasc, gen_pad(' ', f->minlen - ft_strlen(nasc)));
	if (f && f->minlen > ft_strlen(nasc))
		nasc = join_free(gen_pad(' ', f->minlen - ft_strlen(nasc)), nasc);
	return (print_len_free(nasc));
}

int	ft_printp(void *p, t_flag *f)
{
	char	*pasc;

	if (!p)
		pasc = ft_strdup("(nil)");
	else
	{
		pasc = ft_utoa((unsigned long int) p, 16, 0);
		if (f && f->prec > ft_strlen(pasc))
			pasc = join_free(gen_pad('0', f->prec - (ft_strlen(pasc))), pasc);
		pasc = join_free(ft_strdup("0x"), pasc);
	}
	if (f && f->minlen > ft_strlen(pasc))
	{
		if (f->left)
			pasc = join_free(pasc, gen_pad(' ', f->minlen - ft_strlen(pasc)));
		else
			pasc = join_free(gen_pad(' ', f->minlen - ft_strlen(pasc)), pasc);
	}
	return (print_len_free(pasc));
}

int	ft_prints(char *str, t_flag *f)
{
	char	*s;

	if (f && (!f->has_prec || f->prec >= ft_strlen("(null)")) && !str)
		s = ft_strdup("(null)");
	else if (!str)
		s = ft_strdup("");
	else
		s = ft_strdup(str);
	if (f && f->has_prec && f->prec < ft_strlen(s))
		s[f->prec] = 0;
	if (f && f->minlen > ft_strlen(s))
	{
		if (f->left)
			s = join_free(s, gen_pad(' ', f->minlen - ft_strlen(s)));
		else
			s = join_free(gen_pad(' ', f->minlen - ft_strlen(s)), s);
	}
	return (print_len_free(s));
}
