/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:41:22 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/12 13:14:57 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_justify(char str, st_flags *flags, int n)
{
	if(str == '+' || str == '-')
		flags->justify = str;
	else
		flags->justify = 48;
	return(++n);
}

int	ft_zero(char str, st_flags *flags, int n)
{
	if(str == '0')
		flags->zero = 1;
	else
		flags->zero = 0;
	return(++n);
}

void	ft_width(const char *str, int  n, st_flags *flags)
{
	char *width;
	int i;
	int num;
	int save_n;

	i = 0;
	save_n = n;
	while(ft_isdigit(str[n++]))
		++i;
	width = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while(save_n < n)
		width[i++] = str[save_n++];
	num = ft_atoi(width);
	flags->width = num;
	free (width);
}

int ft_asterik(va_list param, const char *str, int n, st_flags *flags)
{
	if (str[n - 1] == '.')
	{
		flags->prec = va_arg(param, int);
		if(flags->prec < 0)
		{
			flags->prec = flags->prec * -1;
			//flags->justify = 's';
			flags->neg_prec = 1;
		}
		return (++n);
	}
	flags->width = va_arg(param, int);
	if(flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->justify = '-';
		//flags->neg_width = 1;
	}
	return (++n);
}

int	ft_prec(const char *str, int  n, st_flags *flags)
{
	char *prec;
	int i;
	int num;
	int save_n;

	i = 0;
	save_n = n;
	while(ft_isdigit(str[n]))
	{
		++n;
		++i;
	}
	prec = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while(save_n < n)
		prec[i++] = str[save_n++];
	num = ft_atoi(prec);
	flags->prec = num;
	free (prec);
	return (i);
}