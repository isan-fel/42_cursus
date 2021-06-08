/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:59:26 by isan              #+#    #+#             */
/*   Updated: 2021/06/08 12:13:32 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void ft_write_hex(unsigned int n, char flag)
{
    char *hex;

    hex = "0123456789abcdef";
    if(flag == 'X')
		hex = "0123456789ABCDEF";
	if(n % 16 > 0)
	{
		ft_write_hex(n / 16, flag);
		printf("%c", hex[n % 16]);//write(1, &hex[n % 16], 1);
	}
}

void	ft_hex(unsigned int n, st_flags flags)
{
	char flag;

    flag = flags.type;
    if(n)
        ft_write_hex(n, flag);
    else if (!n && !flags.dot)
        printf("%c", '0');
    
}