/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/08 19:28:14 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup_string_printf(char *src)
{
	char	*result;
	int		i;

	i = 0;
	if (!src)
		src = "(null)";
	result = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!result)
		return (NULL);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_save_char_array_arg(va_list param, char str, st_flags *flags)
{
	char *temp;

	if(str != 's')
	{
		if (str == 'c')
			temp = ft_char(va_arg(param, int));
		else
			temp = ft_char(str);
		flags->arg = temp;
		ft_write_char(*flags);
	}
	if(str == 's')
	{
		temp = ft_strdup_string_printf(va_arg(param, char *));
		flags->arg = temp;
		ft_write_string(*flags);
	}
	return(temp);
}

char	*ft_save_hexa_pointer_arg(va_list param, char str, st_flags *flags)
{
	char *temp;
	int	hex;
	unsigned long long point_dir;

	hex = 0;
	point_dir = 0;
	if(str == 'x' || str == 'X')
	{
		hex = va_arg(param, unsigned int);
		temp = ft_write_hex(hex, *flags);
		flags->arg = temp;
		ft_write_int(*flags);
	}
	if(str == 'p')
	{
		point_dir = (unsigned long long) va_arg(param, void *);
		temp = ft_write_pointer(point_dir);
		flags->arg = temp;
		ft_write_int(*flags);
	}
	return(temp);
}

int ft_int_negative(char str, st_flags *flags)
{
	//if (str == '-' && (flags->width || flags->prec))
	if (str == '-')
		return (-1);
	if (str == '0' && flags->dot)
		return (0);
	return (1);
}

char	*ft_save_int_arg(va_list param, char str, st_flags *flags)
{
	char *temp;

	if(str == 'd' || str == 'i')
		temp = ft_itoa(va_arg(param, int));
	if(str == 'u')
		temp = ft_uint_itoa(va_arg(param, unsigned int));
	flags->arg = temp;
	ft_write_int(*flags);
	return (temp);
}

int	ft_type_arg(va_list param, char str, st_flags *flags)
{
	char *temp;
	int len = 0;
	int negative = 1;
	
	flags->type = str;
	//printf("type:%c\n", str);
	if(str == 'c' || str == 's' || str == '%')
		temp = ft_save_char_array_arg(param, str, flags);
	if(str == 'd' || str == 'i' || str == 'u')
	{
		temp = ft_save_int_arg(param, str, flags);
		negative = ft_int_negative(temp[0], flags);
	}
	if(str == 'x' || str == 'X' || str == 'p')
		temp = ft_save_hexa_pointer_arg(param, str, flags);
	//printf("temp:%s", temp);
	len = ft_strlen(temp);
	free(temp);
	return (len * negative);
}

int	ft_continue_count(st_flags flags, int len, int count)
{
	/*if (len < 0 && flags.width <= flags.prec && flags.width && flags.prec)
		return (count + ft_count_arglen(flags, len * -1) + 1);
	if (len < 0)	
		return (count + ft_count_arglen(flags, len * -1));
	else
		return (count + ft_count_arglen(flags, len));*/
	if (len < 0)
	{
		len = len * -1;
		//printf("func:%d", ft_count_arglen(flags, len));
		if (flags.width <= flags.prec && ((flags.width && flags.prec) || flags.dot))
		{
			if (len < flags.width || len < flags.prec)
				return (count + ft_count_arglen(flags, len) + 1);
			else
				return (count + ft_count_arglen(flags, len));
		}
		else
			return (count + ft_count_arglen(flags, len));
	}
	return (count + ft_count_arglen(flags, len));
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	st_flags flags;
	int n;
	int count;
	int len;

	count = 0;
	n = 0;
	va_start(param, str);
	while(str[n] != '\0')
	{
		flags = ft_initiate_flags();
		if(str[n] == '%')
		{
			++n;
			n = ft_save_every_flag(param, str, n, &flags);
			len = ft_type_arg(param, str[n++], &flags);
			count = ft_continue_count(flags, len, count);
		}
		else
			count = count + write(1, &str[n++], 1);
	}
	va_end(param);
	return (count);
}