/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:06:08 by isan              #+#    #+#             */
/*   Updated: 2021/07/01 17:13:00 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//esta funcion tiene un return para poder que no siga leyendo cuando 
//entre por un if en concreto, si cambio esa logica el return no lo 
//necesito para nada
int	ft_write_char(st_flags flags)
{
    char str;
    int n;

    n = 0;
    str = flags.arg[0];
    if (flags.width == 0)
        return(write(1, &str, 1));
    while (n < flags.width && flags.justify == '-')
    {
        if (n < 1)
            write(1, &str, 1);
        ++n;
        if (n > 1)
            write(1, " ", 1);
    }
    while (n++ < (flags.width - 1) && flags.justify != '-')
        write(1, " ", 1);
    n = 0;
    while (n++ < 1 && flags.justify != '-')
        write(1, &str, 1);
    return (0);
}