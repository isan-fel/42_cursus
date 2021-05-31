/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/31 20:24:26 by isan-fel         ###   ########.fr       */
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
	flags.type = '%';
	flags.arg = NULL;
	return (flags);
}

/*void	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	//return (1);
}*/

static int	ft_intlen(unsigned int nb)
{
	int	len;

	len = 0;
	/*if (nb == 0)
		len = 1;*/
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

void	ft_justify(char str, st_flags *flags)
{
	if(str == '+' || str == '-')
		flags->justify = str;
	else
		flags->justify = 48;
	//printf("valor de justify: %c<-\n", flags->justify);
}

void	ft_dot(char str, st_flags *flags)
{
	if(str == '.')
		flags->dot = 1;
	else
		flags->dot = 0;
	//printf("valor de dot: %c<-\n", flags->dot);
}

void	ft_zero(char str, st_flags *flags)
{
	if(str == '0')
		flags->zero = 1;
	else
		flags->zero = 0;
	//printf("valor de zero: %c<-\n", flags->zero);
}

void	ft_width(const char *str, int  n, st_flags *flags)
{
	char *width;
	int i;
	int num;

	i = 0;
	//el fallo esta aqui
	width = ft_strdup("");
	while(ft_isdigit(str[n]))
	{
		width[i++] = str[n++];
	}
	width[i] = '\0';
	num = ft_atoi(width);
	flags->width = num;
	free (width);
}

void	ft_type_arg(va_list param, char str, st_flags *flags)
{
	char *temp;
	flags->type = str;
	//printf("valor de type: %c<-\n", flags->type);
	if(str == 'd' || str == 'i')
	{
		temp = ft_itoa(va_arg(param, int));
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
		temp = ft_char(va_arg(param, int));
		flags->arg = temp;
		ft_write_char(*flags);
	}
	free(temp);
	/*else
		flags->zero = 48;
	*/
	//printf("valor de arg: %s<-\n", flags->arg);
}

int	ft_save_every_flag(va_list param, const char *str, int n, st_flags *flags)
{
	if (ft_isalpha(str[n]))
	{
		flags->justify = '0';
		flags->dot = 0;
		flags->zero = 0;
		flags->asterisk = 0;
		flags->width = 0;
	}
	while (!ft_isalpha(str[n]))
	{
		if(str[n] == '+' || str[n] == '-')
		{
			ft_justify(str[n], flags);
			++n;
		}
		if(str[n] == '.')
		{
			ft_dot(str[n], flags);
			++n;
		}
		if(str[n] == '0')
		{
			ft_zero(str[n], flags);
			++n;
		}
		if(ft_isdigit(str[n]))
			ft_width(str, n, flags);
		//printf("valor de width struct: %d<-\n", flags->width);
		if(str[n] == '*')
			flags->width = va_arg(param, int);
		n = n + ft_intlen(flags->width);
		return (n);
	}
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	st_flags flags;
	int n;
	int count;
	int save_count;

	count = 0;
	save_count = 0;
	n = 0;
	flags = ft_initiate_flags();
	va_start(param, str);
	while(str[n] != '\0')
	{
		if(str[n] == '%')
		{
			++n;
			n = ft_save_every_flag(param, str, n, &flags);
			//printf("\nque valor tengo: %c\n", str[n]);
			ft_type_arg(param, str[n], &flags);
			count = count + ft_count_arglen(flags);
			++n;
			//while(flags->width--)
			if(str[n] == '\0')
			{
				//printf("entra al if del break");
				break ;
			}
		}
		else if(str[n] == '\0')
			break ;
		printf("%c", str[n]);//write(1, &str[n], 1);
		++save_count;
		++n;
	}
	va_end(param);
	return (save_count + count - 1);
}

int main()
{
	//int num = 300;
	char c = 'r';
	int n;
	//ft_printf("esto es una prueba: %d", num);
	//n = ft_printf("esto es una prueba:%c<-;ahora el num:%d<-\n", c, num);
	//printf("esto es una prueba:%-5c<-;ahora el num:%-8d<-\n", c, num);
	n = ft_printf("esto es una prueba:%10c<-\n", c);
	printf("esto es una prueba:%10c<-\n", c);
	//printf("return ft_printf: %d\n", n);
	//system("leaks -fullContent a.out");
}