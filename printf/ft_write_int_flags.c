/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:04:09 by isan              #+#    #+#             */
/*   Updated: 2021/07/12 19:27:07 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fill_int_zero_or_space(t_flags *flags)
{
	if (flags->zero)
		flags->len += write(1, "0", 1);
	else
		flags->len += write(1, " ", 1);
}

int	ft_write_pos(t_flags *flags, char *num, int intlen)
{
	int	n;

	n = 0;
	if (flags->justify == '+' && flags->zero)
		flags->len += write(1, &num[n++], 1);
	else if (flags->justify == '+' && !flags->zero)
		++n;
	if (num[0] == '-' && flags->zero)
		flags->len += write(1, &num[0], 1);
	while (n++ < (flags->width - intlen))
		ft_fill_int_zero_or_space(flags);
	if (num[0] == '-' && !flags->zero)
		flags->len += write(1, &num[0], 1);
	if (num[0] == '-')
		n = 1;
	else
		n = 0;
	if (flags->justify == '+' && !flags->zero)
		flags->len += write(1, &flags->justify, 1);
	while (n < intlen)
		flags->len += write(1, &num[n++], 1);
	return (flags->width + 1);
}

void	ft_flags_dot(t_flags *flags, char *num, int intlen)
{
	int	n;

	n = 0;
	if (!flags->prec && !flags->width)
	{
		while (n++ < (flags->width - intlen))
			flags->len += write(1, " ", 1);
		n = 0;
		while (intlen-- && num[0] != '0')
			flags->len += write(1, &num[n++], 1);
	}
	else
		ft_int_prec_or_len(flags, num, intlen);
}

void	ft_write_int(t_flags *flags)
{
	char	*num;
	int		n;
	int		intlen;

	n = 0;
	num = flags->arg;
	intlen = ft_strlen(num);
	if (flags->dot)
		ft_flags_dot(flags, num, intlen);
	else
	{
		if ((!flags->width && !flags->prec) || flags->width < intlen)
			while (n < intlen)
				flags->len += write(1, &num[n++], 1);
		if (flags->justify != '-' && flags->width >= intlen)
			n = ft_write_pos(flags, num, intlen);
		while (n < flags->width && flags->justify == '-')
		{
			if (n < intlen)
				flags->len += write(1, &num[n], 1);
			++n;
			if (n > intlen)
				flags->len += write(1, " ", 1);
		}
	}
}
