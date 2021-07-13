/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:41:22 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 16:13:08 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

int	ft_justify(char str, t_flags *flags)
{
	if (str == '+' || str == '-')
		flags->justify = str;
	else
		flags->justify = 48;
	return (1);
}

int	ft_zero(char str, t_flags *flags)
{
	if (str == '0')
		flags->zero = 1;
	else
		flags->zero = 0;
	return (1);
}

void	ft_width(const char *str, int n, t_flags *flags)
{
	char	*width;
	int		i;
	int		num;
	int		save_n;

	i = 0;
	save_n = n;
	while (ft_isdigit(str[n++]))
		++i;
	width = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (save_n < n)
		width[i++] = str[save_n++];
	num = ft_atoi(width);
	flags->width = num;
	free (width);
}

int	ft_asterik(va_list param, const char *str, int n, t_flags *flags)
{
	if (str[n - 1] == '.')
	{
		flags->prec = va_arg(param, int);
		if (flags->prec < 0)
		{
			flags->prec = flags->prec * -1;
			flags->neg_prec = 1;
		}
		return (++n);
	}
	flags->width = va_arg(param, int);
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->justify = '-';
	}
	return (++n);
}

int	ft_prec(const char *str, int n, t_flags *flags)
{
	char	*prec;
	int		i;
	int		num;
	int		save_n;

	i = 0;
	save_n = n;
	while (ft_isdigit(str[n]))
	{
		++n;
		++i;
	}
	prec = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (save_n < n)
		prec[i++] = str[save_n++];
	num = ft_atoi(prec);
	flags->prec = num;
	free (prec);
	return (i);
}
