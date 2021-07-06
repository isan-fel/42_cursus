/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_preclen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:57:40 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/06 15:42:02 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_preclen_justify(st_flags flags, char *num, int intlen, int prec)
{
    int n;
    int i;

    n = 0;
    i = 0;
    if (num[i] == '-')
        {
            i = i + write(1, "-", 1);
            --intlen;
        }
        while (n++ < (prec - intlen))
            write(1, "0", 1);
        while (intlen--)
        {
            if (prec == 0 && num[0] == '0')
                n = n + write(1, " ", 1);
            else
                n = n + write(1, &num[i++], 1);
        }
        if (num[0] == '-')
            ++n;
        while (n++ <= flags.width)
            write(1, " ", 1);
}

void    ft_prec_morethan_width(st_flags flags, char *num, int intlen, int prec)
{
    int n;
    int i;

    n = 0;
    i = 0;
    /*printf("entra");
    printf("prec:%d\n", prec);
    printf("intlen:%d\n", intlen);*/
    if (num[i] == '-')
    {
        write(1, "-", 1);
        --intlen;
        ++i;
    }
    else if (flags.justify == '+')
        write(1, "+", 1);
    while (prec-- > intlen)
        write(1, "0", 1);
    while (intlen--)
    {
        write(1, &num[i++], 1);
        ++n;
    }
}

void    ft_prec_lessthan_len(st_flags flags, char *num, int intlen, int prec, int n, int i)
{
    if (flags.justify == '+')
        while (n++ < (flags.width - intlen - 1))
            write(1, " ", 1);
    else if (num[0] == '0' && !prec)
        while (n++ <= (flags.width - intlen))
            write(1, " ", 1);
    else
        while (n++ < (flags.width - intlen))
            write(1, " ", 1);
    if (flags.justify == '!')
        write(1, "-", 1);
    if (flags.justify == '+')
        write(1, "+", 1);
    while (intlen-- && (num[0] != '0' || prec))
        write(1, &num[i++], 1);
}

void    ft_prec_mthan_widthlen(st_flags flags, char *num, int intlen, int prec, int n, int i)
{
    if (flags.justify == '+')
        while (n++ < (flags.width - prec - 1))
            write(1, " ", 1);
    else
        while (n++ < (flags.width - prec))
            write(1, " ", 1);
    while (n++ < (flags.width - prec))
        write(1, " ", 1);
    if (flags.justify == '!')
        write(1, "-", 1);
    if (flags.justify == '+')
        write(1, "+", 1);
    while (prec-- > intlen)
        write(1, "0", 1);
    while (intlen--)
        write(1, &num[i++], 1);
}

int change_justify(st_flags flags)
{
    flags.justify = '!';
    return(1);
}

void    ft_int_prec_or_len(st_flags flags, char *num, int intlen)
{
    int n;
    int i;

    i = 0;
    if (flags.justify == '-')
        ft_preclen_justify(flags, num, intlen, flags.prec);
    else
    {
        if (flags.prec >= flags.width)
            ft_prec_morethan_width(flags, num, intlen, flags.prec);
        else
        {
            if (num[i] == '-')
            {
                flags.justify = '!';
                --intlen;
                ++i;
            }
            n = i;
            if (flags.prec <= intlen)
                ft_prec_lessthan_len(flags, num, intlen, flags.prec, n, i);
            else
                ft_prec_mthan_widthlen(flags, num, intlen, flags.prec, n, i);
        }
    }
}