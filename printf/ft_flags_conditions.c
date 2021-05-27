/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/27 19:20:45 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_write_int(st_flags flags)
{
    char *num;
    int n;
    int intlen;

    n = 0;
    num = flags.arg;
    intlen = ft_strlen(num);
    //printf("intlen:%zu", intlen);
    while (n < flags.width)
    {
        if(flags.justify == '-' && n < intlen)
        {
            //printf("intlen:%zu", intlen);
            //while (n < intlen)
            //{
            printf("%c", num[n]);
                //++n;
            //}
            //write(1, &num[n++], 1);
        }
        ++n;
    if (n > intlen)
        printf(" ");
    //write(1, "", 1);
    }
    printf("<-");
}

/*void	ft_write_char(st_flags flags)
{
    
}*/
