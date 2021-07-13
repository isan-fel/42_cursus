/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_preclen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:57:40 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 13:41:00 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_preclen_justify(t_flags *flags, char *num, int intlen, int prec)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (num[i] == '-')
	{
		flags->len += write(1, "-", 1);
		++i;
		--intlen;
	}
	while (n++ < (prec - intlen) && !flags->neg_prec)
		flags->len += write(1, "0", 1);
	while (intlen--)
	{
		if (prec == 0 && num[0] == '0')
			flags->len += write(1, " ", 1);
		else
			flags->len += write(1, &num[i++], 1);
		++n;
	}
	if (num[0] == '-')
		++n;
	while (n++ <= flags->width)
		flags->len += write(1, " ", 1);
}

void	ft_prec_morethan_width(t_flags *flags, char *num, int intlen, int prec)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (num[i] == '-')
	{
		flags->len += write(1, "-", 1);
		--intlen;
		++i;
	}
	else if (flags->justify == '+')
		flags->len += write(1, "+", 1);
	if (flags->neg_prec)
		ft_neg_prec_morethan_width(flags, intlen);
	else
		while (prec-- > intlen)
			flags->len += write(1, "0", 1);
	while (intlen--)
	{
		flags->len += write(1, &num[i++], 1);
		++n;
	}
}

void	ft_prec_lessthan_len(t_flags *flags, char *num, int intlen, int i)
{
	int	n;

	n = i;
	if (flags->neg_prec)
		negprec_len(flags, num, intlen, i);
	else
	{
		if (flags->justify == '+')
			while (n++ < (flags->width - intlen - 1))
				flags->len += write(1, " ", 1);
		else if (num[0] == '0' && !flags->prec)
			while (n++ <= (flags->width - intlen))
				flags->len += write(1, " ", 1);
		else
			while (n++ < (flags->width - intlen))
				flags->len += write(1, " ", 1);
		if (flags->justify == '!')
			flags->len += write(1, "-", 1);
		if (flags->justify == '+')
			flags->len += write(1, "+", 1);
		while (intlen-- && (num[0] != '0' || flags->prec))
			flags->len += write(1, &num[i++], 1);
	}
}

void	ft_prec_mthan_widthlen(t_flags *flags, char *num, int intlen, int i)
{
	int	n;

	n = i;
	if (flags->neg_prec)
		negprec_mt_wlen(flags, num, intlen, i);
	else
	{
		while (n++ < (flags->width - flags->prec))
			flags->len += write(1, " ", 1);
		if (flags->justify == '!')
			flags->len += write(1, "-", 1);
		if (flags->justify == '+')
			flags->len += write(1, "+", 1);
		while (flags->prec-- > intlen && !flags->neg_prec)
			flags->len += write(1, "0", 1);
		while (intlen--)
			flags->len += write(1, &num[i++], 1);
	}
}

void	ft_int_prec_or_len(t_flags *flags, char *num, int intlen)
{
	int	i;

	i = 0;
	if (flags->justify == '-')
		ft_preclen_justify(flags, num, intlen, flags->prec);
	else
	{
		if (flags->prec >= flags->width)
			ft_prec_morethan_width(flags, num, intlen, flags->prec);
		else
		{
			if (num[i] == '-')
			{
				flags->justify = '!';
				--intlen;
				++i;
			}
			if (flags->prec <= intlen)
				ft_prec_lessthan_len(flags, num, intlen, i);
			else
				ft_prec_mthan_widthlen(flags, num, intlen, i);
		}
	}
}
