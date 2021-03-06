/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:06:08 by isan              #+#    #+#             */
/*   Updated: 2021/07/13 13:41:00 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_fill_zero_percent(t_flags *flags, char str)
{
	while (--flags->width)
		flags->len += write(1, "0", 1);
	flags->len += write(1, &str, 1);
	return (1);
}

int	ft_write_char(t_flags *flags)
{
	char	str;
	int		n;

	n = 0;
	str = flags->arg[0];
	if (flags->width == 0)
		return (flags->len += write(1, &str, 1));
	if (flags->zero && flags->type == '%' && flags->justify != '-')
		return (ft_fill_zero_percent(flags, str));
	while (n < flags->width && flags->justify == '-')
	{
		if (n < 1)
			flags->len += write(1, &str, 1);
		++n;
		if (n > 1)
			flags->len += write(1, " ", 1);
	}
	while (n++ < (flags->width - 1) && flags->justify != '-')
		flags->len += write(1, " ", 1);
	n = 0;
	while (n++ < 1 && flags->justify != '-')
		flags->len += write(1, &str, 1);
	return (0);
}
