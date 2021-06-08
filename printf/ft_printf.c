/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/06/08 12:10:44 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

st_flags	ft_initiate_flags(void)
{
	st_flags	flags;

	flags.justify = '0';
	flags.dot = 0;
	flags.zero = 0;
	flags.asterisk = 0;
	flags.width = 0;
	flags.prec = 0;
	flags.type = '%';
	flags.arg = NULL;
	return (flags);
}

static int	ft_intlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb >= 1)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

char	*ft_char(char c_antes)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c_antes;
	str[1] = '\0';
	return (str);	
}

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

int	ft_type_arg(va_list param, char str, st_flags *flags)
{
	char *temp;
	int len = 0;
	int negative = 1;
	int	hex = 0;
	
	flags->type = str;
	if(str == 'd' || str == 'i')
	{
		temp = ft_itoa(va_arg(param, int));
		if (temp[0] == '-' && (flags->width || flags->prec))
			negative = -1;
		if (temp[0] == '0' && flags->dot)
			negative = 0;
		flags->arg = temp;
		ft_write_int(*flags);
	}
	if(str == 'c')
	{
		temp = ft_char(va_arg(param, int));
		flags->arg = temp;
		ft_write_char(*flags);
	}
	if(str == 's')
	{
		temp = ft_strdup(va_arg(param, char *));
		flags->arg = temp;
		ft_write_string(*flags);
	}
	if(str == 'u')
	{
		temp = ft_uint_itoa(va_arg(param, unsigned int));
		flags->arg = temp;
		ft_write_int(*flags);
	}
	if(str == 'x' || str == 'X')
	{
		hex = va_arg(param, unsigned int);
		ft_hex(hex, *flags);
		return (ft_hexlen(hex, *flags));
	}
	len = ft_strlen(temp);
	//printf("temp:%s<-\n", temp);
	//printf("len:%d\n", len);
	free(temp);
	return (len * negative);
}

int ft_asterik(va_list param, int n, st_flags *flags)
{
	flags->width = va_arg(param, int);
	if(flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->justify = '-';
	}
	return(++n);
}

void	ft_prec(const char *str, int  n, st_flags *flags)
{
	char *prec;
	int i;
	int num;
	int save_n;

	i = 0;
	save_n = n;
	while(ft_isdigit(str[n++]))
		++i;
	prec = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while(save_n < n)
		prec[i++] = str[save_n++];
	num = ft_atoi(prec);
	flags->prec = num;
	//printf("prec:%d<-\n", flags->prec);
	free (prec);
}

int	ft_dot_logic(va_list param, const char *str, st_flags *flags, int n)
{
	flags->dot = 1;
	while(str[n] != '.')
	{
		if(str[n] == '*')
		{
			n = ft_asterik(param, n, flags);
			break ;
		}
		if(ft_isdigit(str[n]))
		{
			ft_width(str, n, flags);
			n = n + ft_intlen(flags->width);
			break ;
		}
		++n;
	}
	while(!ft_isalpha(str[++n]))
	{
		if(ft_isdigit(str[n]))
		{
			ft_prec(str, n, flags);
			n = n + ft_intlen(flags->prec);
			//printf("posicion:%c<-\n", str[n]);
			return (n);
		}
	}
	//printf("posicion:%c<-\n", str[n]);
	return(n);
}

int	ft_save_every_flag(va_list param, const char *str, int n, st_flags *flags)
{
	int save_n;
	
	if(str[n] == '+' || str[n] == '-')
		n = ft_justify(str[n], flags, n);
	save_n = n;	
	while (!ft_isalpha(str[n]))
	{
		if(str[n] == '.')
		{
			n = ft_dot_logic(param, str, flags, save_n);
			return(n);
		}
		++n;
	}
	n = save_n;
	flags->dot = 0;			
	if(str[n] == '0')
		n = ft_zero(str[n], flags, n);
	if(ft_isdigit(str[n]))
	{
		ft_width(str, n, flags);
		n = n + ft_intlen(flags->width);
		return (n);
	}
	if(str[n] == '*')
		n = ft_asterik(param, n, flags);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	st_flags flags;
	int n;
	int count;
	int save_count;
	int len;

	count = 0;
	save_count = 0;
	n = 0;
	va_start(param, str);
	while(str[n] != '\0')
	{
		flags = ft_initiate_flags();
		//printf("\nque valor tengo:%c<-\n", str[n]);
		if(str[n] == '%')
		{
			++n;
			n = ft_save_every_flag(param, str, n, &flags);
			//printf("\nque valor tengo: %c\n", str[n]);
			len = ft_type_arg(param, str[n++], &flags);
			//printf("arglen:%d", ft_count_arglen(flags, len));
			if (len < 0 && flags.width <= flags.prec)
			{
				len = len * -1;
				count = count + ft_count_arglen(flags, len) + 1;
			}
			else
				count = count + ft_count_arglen(flags, len);
			//printf("count:%d\n", count);
			//++n;
		}
		else
		{
			printf("%c", str[n]);//write(1, &str[n], 1);
			++n;
			++save_count;
		}
	}
	va_end(param);
	return (save_count + count);
}