/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/31 17:12:49 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_write_pos(st_flags flags, int intlen)
{
    int n;
    char *num;
    
    n = 0;
    num = flags.arg;
    if(flags.justify == '+' && flags.zero)
    {
        write(1, &flags.justify, 1);//printf("%c", flags.justify);
        ++n;
    }
    else if(flags.justify == '+' && !flags.zero)
        ++n;
    while(n < (flags.width - intlen))
    {
        if(flags.zero || (flags.justify == '-' && flags.dot))
            write(1, "0", 1);//printf("0");
        else
            write(1, " ", 1);//printf(" ");
        ++n;
    }
    //printf("valor n: %d", n);
    n = 0;
    if(flags.justify == '+' && !flags.zero)
        write(1, &flags.justify, 1);//printf("%c", flags.justify);
    while(n < intlen)
    {
        write(1, &num[n], 1);//printf("%c", num[n]);
        ++n;
    }
    return (flags.width + 1);
}

void	ft_write_int(st_flags flags)
{
    char *num;
    int n;
    int intlen;

    n = 0;
    num = flags.arg;
    intlen = ft_strlen(num);
    if(flags.width == 0)
    {
        while(n < intlen)
        {
            write(1, &num[n], 1);//printf("%c", num[n]);
            ++n;
        }
    }
    if((flags.justify == '-' && flags.dot) || flags.justify != '-')
        n = ft_write_pos(flags, intlen);
    while(n < flags.width && flags.justify == '-')
    {
        if(n < intlen)
            write(1, &num[n], 1);//printf("%c", num[n]);
        ++n;
        if (n > intlen)
            write(1, " ", 1);//printf(" ");
        //write(1, "", 1);
    }
}

void	ft_write_char(st_flags flags)
{
    char *str;
    int n;
    int strlen;

    n = 0;
    str = flags.arg;
    strlen = ft_strlen(str);
    if(flags.width == 0)
    {
        while(n < strlen)
        {
            write(1, &str[n], 1);//printf("%c", str[n]);
            ++n;
        }
    }
    while(n < flags.width && flags.justify == '-')
    {
        if(n < strlen)
            write(1, &str[n], 1);//printf("%c", str[n]);
        ++n;
        if (n > strlen)
            write(1, " ", 1);//printf(" ");
    }
    while(n < (flags.width - strlen) && flags.justify != '-')
    {
        write(1, " ", 1);//printf(" ");
        ++n;
    }
    n = 0;
    while(n < strlen && flags.justify != '-')
    {
        write(1, &str[n], 1);//printf("%c", str[n]);
        ++n;
    }
}

int ft_count_arglen(st_flags flags)
{
    int len;

    len = ft_strlen(flags.arg);
    if (flags.width > len)
        len = flags.width;
    if (flags.justify == '+')
        ++len;
    return(len);
}