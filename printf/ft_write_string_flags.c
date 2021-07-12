/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/12 12:38:40 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_string_prec_or_len(st_flags *flags, char *str, int len)
{
    int n;
    int prec;

    n = 0;
    prec = flags->prec;
    if (prec <= len)
    {
        while ((n++ < (flags->width - prec)) && flags->justify != '-')
            flags->len += write(1, " ", 1);
        n = 0;
        while (prec--)
            flags->len += write(1, &str[n++], 1);
    }
    else
    {
        while ((n++ < (flags->width - len)) && flags->justify != '-')
            flags->len += write(1, " ", 1);
        n = 0;
        while (len--)
            flags->len += write(1, &str[n++], 1);
    }
    while (n++ < flags->width && flags->justify == '-')
        flags->len += write(1, " ", 1);
}

void ft_write_string(st_flags *flags)
{
    char *str;
    int n;
    int len;
    
    n = 0;
    str = flags->arg;
    len = ft_strlen(str);
    //printf("len:%d\n", len);
    if (flags->dot && !flags->neg_prec)
    {
        if (flags->prec)
            ft_string_prec_or_len(flags, str, len);
        else
        {
            while (n++ < flags->width)
                flags->len += write(1, " ", 1);
        }
    }
    else
    {
        while ((n++ < (flags->width - len)) && flags->justify != '-')
            flags->len += write(1, " ", 1);
        n = 0;
        while (str[n] != '\0')
            flags->len += write(1, &str[n++], 1);
        while (n++ < flags->width && flags->justify == '-')
            flags->len += write(1, " ", 1);
    }
}