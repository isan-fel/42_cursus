/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_preclen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:57:40 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/12 17:03:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_preclen_justify(st_flags *flags, char *num, int intlen, int prec)
{
    int n;
    int i;

    n = 0;
    i = 0;
    if (num[i] == '-')
    {
        flags->len += write(1, "-", 1);
        ++i;
        --intlen;
    }
    while (n++ < (prec - intlen) && !flags->neg_prec)
        flags->len += write(1, "0", 1);
    while (intlen--)
    {
        if (prec == 0 && num[0] == '0')
            flags->len += write(1, " ", 1);
        else
            flags->len += write(1, &num[i++], 1);
        ++n;
    }
    if (num[0] == '-')
        ++n;
    while (n++ <= flags->width)
        flags->len += write(1, " ", 1);
}

void    ft_prec_morethan_width(st_flags *flags, char *num, int intlen, int prec)
{
    int n;
    int i;

    n = 0;
    i = 0;
    //printf("entra");
    /*printf("prec:%d\n", prec);
    printf("intlen:%d\n", intlen);*/
    if (num[i] == '-')
    {
        flags->len += write(1, "-", 1);
        --intlen;
        ++i;
    }
    else if (flags->justify == '+')
        flags->len += write(1, "+", 1);
    if (flags->neg_prec)
    {
        if (flags->zero)
        {
            while (flags->width-- > intlen)
            flags->len += write(1, "0", 1);
        }
        else
        {
            while (flags->width-- > intlen)
                flags->len += write(1, " ", 1);
        }
    }
    else
    {
        while (prec-- > intlen)
            flags->len += write(1, "0", 1);
    }
    while (intlen--)
    {
        flags->len += write(1, &num[i++], 1);
        ++n;
    }
}

void    ft_prec_lessthan_len(st_flags *flags, char *num, int intlen, int prec, int n, int i)
{
    if (flags->neg_prec)
    {
        if (flags->justify == '+')
        while (n++ < (flags->width - intlen - 1))
            flags->len += write(1, " ", 1);
    else if (num[0] == '0' && !prec)
        while (n++ <= (flags->width - intlen))
            flags->len += write(1, " ", 1);
    else if (flags->zero && flags->neg_prec && flags->justify !='!')
        while (flags->width-- > intlen)
            flags->len += write(1, "0", 1);
    else if (!flags->zero)
        while (n++ < (flags->width - intlen))
            flags->len += write(1, " ", 1);
    if (flags->justify == '!')
        flags->len += write(1, "-", 1);
    if (flags->justify == '+')
        flags->len += write(1, "+", 1);
    if (flags->zero && flags->neg_prec && flags->justify =='!')
        while (flags->width-- > intlen + 1)
            flags->len += write(1, "0", 1);
    while (intlen-- && (num[0] != '0' || prec))
        flags->len += write(1, &num[i++], 1);
    }
    else
    {
    if (flags->justify == '+')
        while (n++ < (flags->width - intlen - 1))
            flags->len += write(1, " ", 1);
    else if (num[0] == '0' && !prec)
        while (n++ <= (flags->width - intlen))
            flags->len += write(1, " ", 1);
    else
        while (n++ < (flags->width - intlen))
            flags->len += write(1, " ", 1);
    if (flags->justify == '!')
        flags->len += write(1, "-", 1);
    if (flags->justify == '+')
        flags->len += write(1, "+", 1);
    while (intlen-- && (num[0] != '0' || prec))
        flags->len += write(1, &num[i++], 1);
    }
}

void    ft_prec_mthan_widthlen(st_flags *flags, char *num, int intlen, int prec, int n, int i)
{
    /*if (flags->justify == '+')
        while (n++ < (flags->width - prec - 1))
            flags->len += write(1, " ", 1);*/
    if (flags->neg_prec)
        {
            if (flags->zero)
            {
                while (n++ < (flags->width - intlen))
                    flags->len += write(1, "0", 1);
            }
            else
            {
                while (n++ < (flags->width - intlen))
                    flags->len += write(1, " ", 1);
            }
                if (flags->justify == '!')
                    flags->len += write(1, "-", 1);
                if (flags->justify == '+')
                    flags->len += write(1, "+", 1);
                while (intlen--)
                    flags->len += write(1, &num[i++], 1);
        }
    else
    {
    while (n++ < (flags->width - prec))
        flags->len += write(1, " ", 1);
    if (flags->justify == '!')
        flags->len += write(1, "-", 1);
    if (flags->justify == '+')
        flags->len += write(1, "+", 1);
    while (prec-- > intlen && !flags->neg_prec)
        flags->len += write(1, "0", 1);
    while (intlen--)
        flags->len += write(1, &num[i++], 1);
    }
}

/*void ft_obviate_prec(st_flags *flags, char *num, int intlen, int n, int i)
{
    while(n++ < (flags->width - prec))

}*/

void    ft_int_prec_or_len(st_flags *flags, char *num, int intlen)
{
    int n;
    int i;

    i = 0;
    if (flags->justify == '-')
        ft_preclen_justify(flags, num, intlen, flags->prec);
    else
    {
        if (flags->prec >= flags->width)
            ft_prec_morethan_width(flags, num, intlen, flags->prec);
        else
        {
            if (num[i] == '-')
            {
                flags->justify = '!';
                --intlen;
                ++i;
            }
            n = i;
            /*if (flags->neg_prec)
                ft_obviate_prec(flags, num, intlen, n, i);*/
            if (flags->prec <= intlen)
                ft_prec_lessthan_len(flags, num, intlen, flags->prec, n, i);
            else
                ft_prec_mthan_widthlen(flags, num, intlen, flags->prec, n, i);
        }
    }
}