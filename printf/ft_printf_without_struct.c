/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/24 20:17:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_char(char c_antes)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c_antes;
	str[1] = '\0';
	return (str);	
}

int	ft_flags(char *str, int n)
{
	if(str[n] == '+')
	{
		printf("%s", ft_char(str[n]));
		++n;
	}
	return(n);
}

int	ft_width(char *arg)
{
	int width;
	int i;

	width = 0;
	i = 0;
	while(arg[i])
	{
		//printf("\n%c", arg[i]);
		if(ft_isdigit(arg[i]) && arg[i] != '0')
			width = ft_atoi(&arg[i]);
		//printf("\natoi: %d\n", width);
		++i;
	}
	return(width);
}

void	ft_type(va_list param, char *arg, int width)
{
	//printf("que caracter estoy: %c\n", str[n]);
	int n;
	int num;

	n = ft_strlen(arg) - 1;
	printf("\nult_agr:%c<-\n", arg[n]);
	width = 0;
	if (arg[n] == 'd' || arg[n] == 'i')
	{
		num = va_arg(param, int);
		printf("num:%d<-\n", num);
	}
	if (arg[n] == 'c')
		printf("%s", ft_char(va_arg(param, int)));
	//return (++n);
}

char *ft_save_every_flags(char *str, int n, char *arg)
{
	//char *arg;
	int i;

	i = 0;
	//arg = ft_strdup("");
	//printf("llega aqui");
	while(!ft_isalpha(str[n]))
	{
		arg[i++] = str[n++];
	}
	arg[i] = str[n];
	arg[++i] = '\0';
	return(arg); 
}

void	ft_printf(char *str, ...)
{
	va_list	param;
	int n;
	char *arg;

	n = 0;
	arg = ft_strdup("");
	va_start(param, str);
	while(str[n] != '\0')
	{
		if(str[n] == '%')
		{
			++n;
			arg = ft_save_every_flags(str, n, arg);
			//printf("arg->%s\n", arg);
			ft_type(param, arg, ft_width(arg));
			n = n + ft_strlen(arg) - 1;
			//n = ft_flags(str, n);
			//n = ft_width(str, n);
			//ft_type(param, str, n);
			if (str[n + 1] == '\0')
			{
				printf("entra al if del break");
				break ;
			}
		}
		else
			printf("%c", str[n]);
		++n;
		//printf("\n%d", n);
	}
	va_end(param);
}

int main()
{
	int num = 3;
	char c = 'r';
	//ft_printf("esto es una prueba: %d", num);
	ft_printf("esto es una prueba: %c ;ahora el num: %+5d\n", c, num);
	printf("esto es una prueba: %c ;ahora el num:%+5d<-\n", c, num);
}
