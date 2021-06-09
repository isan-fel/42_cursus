/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:59:26 by isan              #+#    #+#             */
/*   Updated: 2021/06/09 19:39:52 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/
int ft_hexlen(unsigned int n, st_flags flags)
{
    int i;

    i = 0;
    if (n <= 16)
    {
        if (n == 0 && flags.dot)
            return (0);
        return (1);
    }
    while(n % 16 > 0)
    {
        ++i;
        n = n / 16;
    }
    return (i);
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
/*
size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		++n;
	return (n);
}*/


void    ft_strrev(char *str, int i)
{
    char tmp;
    //int i;
    int j;

    //i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
        i++;
    }
    //return (str);
}

//void ft_write_hex(unsigned int n, char flag)
char *ft_write_hex(unsigned int n, st_flags flags)
{
    char *hex;
    char *temp;
    int i;
    int hexlen;

    i = 0;
    hex = "0123456789abcdef";
    if (flags.type == 'X')
		hex = "0123456789ABCDEF";
    if (flags.type == 'p')
        hexlen = ft_intlen(n) + 2;
    else
        hexlen = ft_intlen(n);
    //printf("hexlen:%d\n", hexlen);
    temp = malloc((hexlen + 1) * sizeof(char));
    if (flags.type == 'p')
    {
        temp[i++] = '0';
        temp[i++] = 'x';
    }
    while(n > 16)
	{
		//ft_write_hex(n / 16, flag);
        temp[i] = hex[n % 16];
        n = n / 16;
        ++i;
        //printf("%c", hex[n % 16]);//write(1, &hex[n % 16], 1);
	}
    if (n < 16)
        temp[i++] = hex[n % 16];//write(1, &hex[n % 16], 1);
    temp[i] = '\0';
    //printf("i:%d\n", i);
    if (flags.type == 'p')
        ft_strrev(temp, 2);
    else
        ft_strrev(temp, 0);
    return (temp);
}
/*void	ft_hex(unsigned int n, st_flags flags)
{
	char flag;

    flag = flags.type;
    if(n)
        ft_write_hex(n, flag);
    else if (!n && !flags.dot)
        printf("%c", '0');
    
}*/

/*int main()
{
    unsigned int n = 44488548;

    printf("->%s<-\n", ft_write_hex(n));
    printf("->%x<-\n", n);
    
}
*/