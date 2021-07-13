/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 16:04:06 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

void	ft_string_prec_or_len(t_flags *flags, char *str, int len)
{
	int	n;

	n = 0;
	if (flags->prec <= len)
	{
		while ((n++ < (flags->width - flags->prec)) && flags->justify != '-')
			flags->len += write(1, " ", 1);
		n = 0;
		while (flags->prec--)
			flags->len += write(1, &str[n++], 1);
	}
	else
	{
		while ((n++ < (flags->width - len)) && flags->justify != '-')
			flags->len += write(1, " ", 1);
		n = 0;
		while (len--)
			flags->len += write(1, &str[n++], 1);
	}
	while (n++ < flags->width && flags->justify == '-')
		flags->len += write(1, " ", 1);
}

void	ft_string_without_dot(t_flags *flags, char *str, int len)
{
	int	n;

	n = 0;
	while ((n++ < (flags->width - len)) && flags->justify != '-')
		flags->len += write(1, " ", 1);
	n = 0;
	while (str[n] != '\0')
		flags->len += write(1, &str[n++], 1);
	while (n++ < flags->width && flags->justify == '-')
		flags->len += write(1, " ", 1);
}

void	ft_write_string(t_flags *flags)
{
	char	*str;
	int		n;
	int		len;

	n = 0;
	str = flags->arg;
	len = ft_strlen(str);
	if (flags->dot && !flags->neg_prec)
	{
		if (flags->prec)
			ft_string_prec_or_len(flags, str, len);
		else
			while (n++ < flags->width)
				flags->len += write(1, " ", 1);
	}
	else
		ft_string_without_dot(flags, str, len);
}
