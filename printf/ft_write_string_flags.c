/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/06/08 10:07:29 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_string_prec_or_len(st_flags flags, char *str, int len)
{
    int n;
    int prec;

    n = 0;
    prec = flags.prec;
    if (prec <= len)
    {
        while ((n++ < (flags.width - prec)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (prec--)
            printf("%c", str[n++]);
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (len--)
            printf("%c", str[n++]);
    }
    while (n++ < flags.width && flags.justify == '-')
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
    if (flags.dot)
    {
        if (flags.prec)
        {
            //printf("entra aqui");
            ft_string_prec_or_len(flags, str, len);
        }
        else
        {
            //printf("width:%d", flags.width);
            while (n++ < flags.width)
                printf(" ");//write(1, " ", 1);
        }
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (str[n] != '\0')
        {
            printf("%c", str[n]);
            ++n;
        }
        while (n++ < flags.width && flags.justify == '-')
            printf(" ");//write(1, " ", 1); 
    }
}