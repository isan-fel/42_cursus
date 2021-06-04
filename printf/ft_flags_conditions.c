/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/06/03 20:38:43 by isan-fel         ###   ########.fr       */
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
        printf("%c", flags.justify);//write(1, &flags.justify, 1);
        ++n;
    }
    else if(flags.justify == '+' && !flags.zero)
        ++n;
    while(n < (flags.width - intlen))
    {
        if(flags.zero || (flags.justify == '-' && flags.dot))
            printf("0");//write(1, "0", 1);
        else
            printf(" ");//write(1, " ", 1);
        ++n;
    }
    //printf("valor n: %d", n);
    n = 0;
    if(flags.justify == '+' && !flags.zero)
        printf("%c", flags.justify);//write(1, &flags.justify, 1);
    while(n < intlen)
    {
        printf("%c", num[n]);//write(1, &num[n], 1);
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
            printf("%c", num[n]);//write(1, &num[n], 1);
            ++n;
        }
    }
    if(((flags.justify == '-' && flags.dot) || flags.justify != '-') && flags.width)
        n = ft_write_pos(flags, intlen);
    while(n < flags.width && flags.justify == '-')
    {
        if(n < intlen)
            printf("%c", num[n]);//write(1, &num[n], 1);
        ++n;
        if (n > intlen)
            printf(" ");//write(1, " ", 1);
        //write(1, "", 1);
    }
}

int	ft_write_char(st_flags flags)
{
    char *str;
    int n;
    int strlen;

    n = 0;
    str = flags.arg;
    strlen = ft_strlen(str);
    if(flags.width == 0)
    {
        while(n + 1 < strlen)
        {
            printf("%c", str[n]);//write(1, &str[n], 1);
            ++n;
        }
    }
    if(str[n] == 0)
    {
        printf(" ");//write(1, &str[n], 1);
        return(1);
    }
    while(n < flags.width && flags.justify == '-')
    {
        if(n < strlen)
            printf("%c", str[n]);//write(1, &str[n], 1);
        ++n;
        if (n > strlen)
            printf(" ");//write(1, " ", 1);
    }
    while(n < (flags.width - strlen) && flags.justify != '-')
    {
        printf(" ");//write(1, " ", 1);
        ++n;
    }
    n = 0;
    while(n < strlen && flags.justify != '-')
    {
        printf("%c", str[n]);//write(1, &str[n], 1);
        ++n;
    }
    return(0);
}

void    ft_prec_or_len(st_flags flags, char *str, int len)
{
    int n;
    int prec;

    n = 0;
    prec = flags.prec;
    if(prec <= len)
    {
        while((n++ < (flags.width - prec)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while(prec--)
            printf("%c", str[n++]);
    }
    else
    {
        while((n++ <= (flags.width - (prec - len))) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while(len--)
            printf("%c", str[n++]);
    }
    while(n++ < flags.width && flags.justify == '-')
        printf(" ");//write(1, " ", 1);
}

void ft_write_string(st_flags flags)
{
    char *str;
    int n;
    int len;

    n = 0;
    str = flags.arg;
    len = ft_strlen(str);
    if(flags.dot)
    {
        if(flags.prec)
        {
            //printf("entra aqui");
            ft_prec_or_len(flags, str, len);
        }
        else
        {
            //printf("width:%d", flags.width);
            while(n++ < flags.width)
            {
                
                printf(" ");//write(1, " ", 1);
            }
        }
    }
    else
    {
        while((n++ < (flags.width - len)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while(str[n] != '\0')
        {
            printf("%c", str[n]);
            ++n;
        }
        while(n++ < flags.width && flags.justify == '-')
            printf(" ");//write(1, " ", 1); 
    }
}

int ft_count_arglen(st_flags flags, int len)
{
    if(flags.prec && flags.prec >= flags.width)
    {
        if(flags.prec < len)
            return(flags.prec);
        else
            return(len);
    }
    if(flags.width > len || flags.dot)
        len = flags.width;
    if (flags.justify == '+')
        ++len;
    return(len);
}