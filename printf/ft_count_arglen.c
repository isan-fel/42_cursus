/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arglen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:06:57 by isan              #+#    #+#             */
/*   Updated: 2021/06/08 12:07:33 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_count_intflag(st_flags flags, int len)
{
    if (flags.prec >= flags.width && flags.prec > len)
        return (flags.prec);
    if (flags.width > len)
        return (flags.width);
    if (flags.justify == '+' && flags.width < len)
        ++len;
    return (len);
}

int ft_count_arglen(st_flags flags, int len)
{
    //printf("len:%d\n", len);
    if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u' || flags.type == 'x')
        return (ft_count_intflag(flags, len));
    if (len == 0 && flags.type == 'c' && flags.width == 0)
        return(1);
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