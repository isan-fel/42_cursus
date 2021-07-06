/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:59:26 by isan              #+#    #+#             */
/*   Updated: 2021/07/06 16:56:22 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_strrev(char *str, int i)
{
    char tmp;
    int j;

    j = ft_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
        i++;
    }
}

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
    hexlen = ft_intlen(n);
    //printf("n:%u\n", n);
    //printf("hexlen:%d<-\n", hexlen);
    temp = malloc((hexlen + 1) * sizeof(char));
    while(n >= 16)
	{
        temp[i++] = hex[n % 16];
        n = n / 16;
	}
    if (n < 16)
        temp[i++] = hex[n % 16];
    temp[i] = '\0';
    ft_strrev(temp, 0);
    //printf("temp:%s<-\n", temp);
    return (temp);
}

static int	ft_pointlen(unsigned long long nb)
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

char *ft_write_pointer(unsigned long long n)
{
    char *hex;
    char *temp;
    int i;
    int hexlen;

    i = 0;
    hex = "0123456789abcdef";
    hexlen = ft_pointlen(n) + 2;
    //printf("n:%llu\n", n);
    //printf("hexlen:%d<-\n", hexlen);
    temp = malloc((hexlen + 1) * sizeof(char));
    temp[i++] = '0';
    temp[i++] = 'x';
    while(n >= 16)
	{
        temp[i++] = hex[n % 16];
        n = n / 16;
	}
    if (n < 16)
        temp[i++] = hex[n % 16];
    temp[i] = '\0';
    ft_strrev(temp, 2);
    //printf("temp:%s<-\n", temp);
    return (temp);
}