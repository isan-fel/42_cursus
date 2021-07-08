/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arglen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:06:57 by isan              #+#    #+#             */
/*   Updated: 2021/07/08 20:02:35 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_count_intflag(st_flags flags, int len)
{
    if ((flags.type == 'x' || flags.type == 'X') && flags.prec == 0 && flags.width == 0 && flags.dot == 1 && flags.arg[0] == '0')
        return (0);
    if (flags.prec >= flags.width && flags.prec > len)
    { 
        if (flags.neg_prec)
            return (len);
        else
            return (flags.prec);
    }
    if (flags.width > len)
        return (flags.width);
    if (flags.justify == '+' && flags.width < len)
        ++len;
    return (len);
}

int ft_count_arglen(st_flags flags, int len)
{
    //printf("len:%d\n", len);
    if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u' || flags.type == 'x' || flags.type == 'X')
        return (ft_count_intflag(flags, len));
    if (len == 0 && flags.type == 'c' && flags.width == 0)
        return(1);
    if (flags.type == 's' && flags.neg_prec)
        return (len);
    if (flags.prec && flags.prec >= flags.width)
    {
        if (flags.prec < len)
            return (flags.prec);
        else
            return (len);
    }
    if (flags.width > len || flags.dot)
        len = flags.width;
    if (flags.justify == '+')
        ++len;
    return (len);
}