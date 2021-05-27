/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/27 19:20:44 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

st_flags	ft_initiate_flags(void)
{
	st_flags	flags;

	flags.justify = '0';
	flags.dot = -1;
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
		flags->dot = str;
	else
		flags->dot = 48;
	//printf("valor de dot: %c<-\n", flags->dot);
}

void	ft_zero(char str, st_flags *flags)
{
	if(str == '0')
		flags->zero = 49;
	else
		flags->zero = 48;
	//printf("valor de zero: %c<-\n", flags->zero);
}

void	ft_width(const char *str, int  n, st_flags *flags)
{
	char *width;
	int i;
	int num;

	i = 0;
	width = ft_strdup("");
	while(ft_isdigit(str[n]))
		width[i++] = str[n++];
	width[i] = '\0';
	num = ft_atoi(width);
	flags->width = num;
}

void	ft_type_arg(va_list param, char str, st_flags *flags)
{
	flags->type = str;
	//printf("valor de type: %c<-\n", flags->type);
	if(str == 'd' || str == 'i')
	{
		flags->arg = ft_itoa(va_arg(param, int));
		ft_write_int(*flags);
	}
	if(str == 'c')
	{
		flags->arg = ft_char(va_arg(param, int));
		//ft_write_char(flags);
	}
	if(str == 's')
		flags->arg = ft_char(va_arg(param, int));
	else
		flags->zero = 48;
	//printf("valor de arg: %s<-\n", flags->arg);
}

int	ft_save_every_flag(const char *str, int n, st_flags *flags)
{
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
		n = n + ft_intlen(flags->width);
		return (n);
	}
	return (n);
}

void	ft_printf(const char *str, ...)
{
	va_list	param;
	st_flags flags;
	int n;

	n = 0;
	va_start(param, str);
	flags = ft_initiate_flags();
	while(str[n] != '\0')
	{
		if(str[n] == '%')
		{
			++n;
			n = ft_save_every_flag(str, n, &flags);
			ft_type_arg(param, str[n], &flags);
			++n;
			//while(flags->width--)
			{

			}
			if (str[n + 1] == '\0')
			{
				//printf("entra al if del break");
				break ;
			}
		}
		else
			write(1, &str[n], 1);
		//printf("%c", str[n]);
		++n;
		//printf("\n%d", n);
	}
	va_end(param);
}

int main()
{
	int num = 300;
	char c = 'r';
	//ft_printf("esto es una prueba: %d", num);
	ft_printf("esto es una prueba: %c ;ahora el num: %-10d\n", c, num);
	printf("esto es una prueba: %c ;ahora el num:%-10d<-\n", c, num);
}
