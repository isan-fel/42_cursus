/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/01 17:37:58 by isan-fel         ###   ########.fr       */
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
            write(1, " ", 1);//printf(" ");
        n = 0;
        while (prec--)
            write(1, &str[n++], 1);//printf("%c", str[n++]);
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            write(1, " ", 1);//printf(" ");
        n = 0;
        while (len--)
            write(1, &str[n++], 1);//printf("%c", str[n++]);
    }
    while (n++ < flags.width && flags.justify == '-')
        write(1, " ", 1);//printf(" ");
}

void ft_write_string(st_flags flags)
{
    char *str;
    int n;
    int len;
    char *temp;

    n = 0;
    str = flags.arg;
    if (!str)
    {
        temp = ft_strdup("(null)");
        str = temp;
        free(temp);
    }
    len = ft_strlen(str);
    if (flags.dot)
    {
        if (flags.prec)
            ft_string_prec_or_len(flags, str, len);
        else
        {
            while (n++ < flags.width)
                write(1, " ", 1);//printf(" ");
        }
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            write(1, " ", 1);//printf(" ");
        n = 0;
        while (str[n] != '\0')
            write(1, &str[n++], 1);//printf("%c", str[n++]);
        while (n++ < flags.width && flags.justify == '-')
            write(1, " ", 1);//printf(" ");
    }
}