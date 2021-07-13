/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_prec_int_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:24:35 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 16:12:50 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

void	ft_neg_prec_morethan_width(t_flags *flags, int intlen)
{
	if (flags->zero)
	{
		while (flags->width-- > intlen)
			flags->len += write(1, "0", 1);
	}
	else
	{
		while (flags->width-- > intlen)
			flags->len += write(1, " ", 1);
	}
}

void	negprec_len(t_flags *flags, char *num, int intlen, int i)
{
	int	n;

	n = i;
	if (flags->justify == '+')
		while (n++ < (flags->width - intlen - 1))
			flags->len += write(1, " ", 1);
	else if (num[0] == '0' && !flags->prec)
		while (n++ <= (flags->width - intlen))
			flags->len += write(1, " ", 1);
	else if (flags->zero && flags->neg_prec && flags->justify != '!')
		while (flags->width-- > intlen)
			flags->len += write(1, "0", 1);
	else if (!flags->zero)
		while (n++ < (flags->width - intlen))
			flags->len += write(1, " ", 1);
	if (flags->justify == '!')
		flags->len += write(1, "-", 1);
	if (flags->justify == '+')
		flags->len += write(1, "+", 1);
	if (flags->zero && flags->neg_prec && flags->justify == '!')
		while (flags->width-- > intlen + 1)
			flags->len += write(1, "0", 1);
	while (intlen-- && (num[0] != '0' || flags->prec))
		flags->len += write(1, &num[i++], 1);
}

void	negprec_mt_wlen(t_flags *flags, char *num, int intlen, int i)
{
	int	n;

	n = i;
	if (flags->zero)
		while (n++ < (flags->width - intlen))
			flags->len += write(1, "0", 1);
	else
		while (n++ < (flags->width - intlen))
			flags->len += write(1, " ", 1);
	if (flags->justify == '!')
		flags->len += write(1, "-", 1);
	if (flags->justify == '+')
		flags->len += write(1, "+", 1);
	while (intlen--)
		flags->len += write(1, &num[i++], 1);
}
