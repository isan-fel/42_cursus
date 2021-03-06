/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 15:45:20 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_save_char_array_arg(va_list param, char str, t_flags *flags)
{
	char	*temp;

	if (str != 's')
	{
		if (str == 'c')
			temp = ft_char(va_arg(param, int));
		else
			temp = ft_char(str);
		flags->arg = temp;
		ft_write_char(flags);
	}
	if (str == 's')
	{
		temp = ft_strdup_string_printf(va_arg(param, char *));
		flags->arg = temp;
		ft_write_string(flags);
	}
	return (temp);
}

char	*ft_save_hexa_pointer_arg(va_list param, char str, t_flags *flags)
{
	char				*temp;
	int					hex;
	unsigned long long	point_dir;

	hex = 0;
	point_dir = 0;
	if (str == 'x' || str == 'X')
	{
		hex = va_arg(param, unsigned int);
		temp = ft_write_hex(hex, *flags);
		flags->arg = temp;
		ft_write_int(flags);
	}
	if (str == 'p')
	{
		point_dir = (unsigned long long) va_arg(param, void *);
		temp = ft_write_pointer(point_dir);
		flags->arg = temp;
		ft_write_int(flags);
	}
	return (temp);
}

char	*ft_save_int_arg(va_list param, char str, t_flags *flags)
{
	char	*temp;

	if (str == 'd' || str == 'i')
		temp = ft_itoa(va_arg(param, int));
	if (str == 'u')
		temp = ft_uint_itoa(va_arg(param, unsigned int));
	flags->arg = temp;
	ft_write_int(flags);
	return (temp);
}

int	ft_type_arg(va_list param, char str, t_flags *flags)
{
	char	*temp;

	flags->type = str;
	while (!ft_strchr(FLAGS, str))
		return (0);
	if (str == 'c' || str == 's' || str == '%')
		temp = ft_save_char_array_arg(param, str, flags);
	if (str == 'd' || str == 'i' || str == 'u')
		temp = ft_save_int_arg(param, str, flags);
	if (str == 'x' || str == 'X' || str == 'p')
		temp = ft_save_hexa_pointer_arg(param, str, flags);
	free(temp);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		param;
	t_flags		flags;
	int			n;

	n = 0;
	va_start(param, str);
	flags.len = 0;
	while (str[n] != '\0')
	{
		ft_initiate_flags(&flags);
		if (str[n] == '%')
		{
			if (str[++n] == '\0')
				return (flags.len);
			n = save_every_flag(param, str, n, &flags);
			if (str[n] == '\0')
				return (flags.len);
			ft_type_arg(param, str[n++], &flags);
		}
		else
			flags.len += write(1, &str[n++], 1);
	}
	va_end(param);
	return (flags.len);
}
