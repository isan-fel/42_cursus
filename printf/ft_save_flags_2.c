/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_flags_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:43:33 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/12 19:55:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_save_width(const char *str, t_flags *flags, int n)
{
	ft_width(str, n, flags);
	return (n + ft_intlen(flags->width));
}

int	ft_dot_logic(va_list param, const char *str, t_flags *flags, int n)
{
	while (str[n] != '.')
	{
		if (str[n] == '*')
		{
			n = ft_asterik(param, str, n, flags);
			break ;
		}
		if (ft_isdigit(str[n]))
		{
			n = ft_save_width(str, flags, n);
			break ;
		}
		++n;
	}
	while (!ft_isalpha(str[++n]))
	{
		if (str[n] == '*')
		{
			n = ft_asterik(param, str, n, flags);
			break ;
		}
		if (ft_isdigit(str[n]))
			return (n + ft_prec(str, n, flags));
	}
	return (n);
}

int	save_every_flag(va_list param, const char *str, int n, t_flags *flags)
{
	int	save_n;

	while (str[n] == '+' || str[n] == '-' || str[n] == '0')
	{
		if (str[n] == '+' || str[n] == '-')
			n = ft_justify(str[n], flags, n);
		if (str[n] == '0')
			n = ft_zero(str[n], flags, n);
	}
	save_n = n;
	while (!ft_isalpha(str[n]) && str[n] != '%')
	{
		if (str[n] == '.')
		{	
			flags->dot = 1;
			return (ft_dot_logic(param, str, flags, save_n));
		}
		++n;
	}
	n = save_n;
	if (ft_isdigit(str[n]))
		n = ft_save_width(str, flags, n);
	if (str[n] == '*')
		n = ft_asterik(param, str, n, flags);
	return (n);
}
