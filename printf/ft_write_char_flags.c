/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:06:08 by isan              #+#    #+#             */
/*   Updated: 2021/06/08 10:12:16 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//esta funcion tiene un return para poder que no siga leyendo cuando 
//entre por un if en concreto, si cambio esa logica el return no lo 
//necesito para nada
int	ft_write_char(st_flags flags)
{
    char *str;
    int n;
    int strlen;

    n = 0;
    str = flags.arg;
    strlen = ft_strlen(str);
    //printf("width:%d\n", flags.width);
    //printf("strlen:%d\n", strlen);
    if (flags.width == 0)
    {
        if (strlen == 1)
        {
        printf("%c", str[n]);//write(1, &str[n], 1);
        return (1);
        }
        while (n < strlen - 1)
        {
            printf("%c", str[n]);//write(1, &str[n], 1);
            ++n;
        }
    }
    if (str[n] == 0)
        ++n;
    while (n < flags.width && flags.justify == '-')
    {
        if (n < strlen)
            printf("%c", str[n]);//write(1, &str[n], 1);
        ++n;
        if (n > strlen)
            printf(" ");//write(1, " ", 1);
    }
    while (n < (flags.width - strlen) && flags.justify != '-')
    {
        printf(" ");//write(1, " ", 1);
        ++n;
    }
    n = 0;
    while (n < strlen && flags.justify != '-')
    {
        printf("%c", str[n]);//write(1, &str[n], 1);
        ++n;
    }
    return (0);
}