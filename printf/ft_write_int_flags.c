/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:04:09 by isan              #+#    #+#             */
/*   Updated: 2021/06/08 10:05:11 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_write_pos(st_flags flags, int intlen)
{
    int n;
    char *num;
    
    n = 0;
    num = flags.arg;
    if(flags.justify == '+' && flags.zero)
    {
        printf("%c", flags.justify);//write(1, &flags.justify, 1);
        ++n;
    }
    else if(flags.justify == '+' && !flags.zero)
        ++n;
    while(n < (flags.width - intlen))
    {
        if(flags.zero || (flags.justify == '-' && flags.dot))
            printf("0");//write(1, "0", 1);
        else
            printf(" ");//write(1, " ", 1);
        ++n;
    }
    //printf("valor n: %d", n);
    n = 0;
    if(flags.justify == '+' && !flags.zero)
        printf("%c", flags.justify);//write(1, &flags.justify, 1);
    while(n < intlen)
    {
        printf("%c", num[n]);//write(1, &num[n], 1);
        ++n;
    }
    return (flags.width + 1);
}

void    ft_int_prec_or_len(st_flags flags, char *num, int intlen)
{
    int n;
    int prec;
    int i;

    n = 0;
    i = 0;
    prec = flags.prec;
    if (flags.justify == '-')
    {
        if (num[i] == '-')
        {
            printf("%c", '-');
            --intlen;
            ++i;
            
        }
            while (n++ < (prec - intlen))
                printf("%c", '0');
            while (intlen--)
            {
                printf("%c", num[i++]);
                ++n;
            }
            if (num[0] == '-')
                ++n;
            while (n++ <= flags.width)
                printf(" ");
    }
    else
    {
            if (prec >= flags.width)
            {
                if (num[i] == '-')
                {
                    printf("%c", '-');
                    --intlen;
                    ++i;
                }
                else if (flags.justify == '+')
                    printf("%c", '+');
                while (prec-- > intlen)
                    printf("%c", '0');
                while (intlen--)
                {
                    printf("%c", num[i++]);
                    ++n;
                }
            }
            else
            {
                if (num[i] == '-')
                {
                    flags.justify = '!';
                    --intlen;
                    ++i;
                    ++n;
                }
                if (prec <= intlen)
                {
                    if (flags.justify == '+')
                        while (n++ < (flags.width - intlen - 1))
                            printf(" ");//write(1, " ", 1);
                    else if (num[0] == '0' && !prec)
                        while (n++ <= (flags.width - intlen))
                            printf(" ");//write(1, " ", 1);
                    else
                        while (n++ < (flags.width - intlen))
                            printf(" ");//write(1, " ", 1);
                    if (flags.justify == '!')
                        printf("%c", '-');
                    if (flags.justify == '+')
                        printf("%c", '+');
                    while (intlen-- && (num[0] != '0' || prec))
                        printf("%c", num[i++]);
                }
                else
                {
                    if (flags.justify == '+')
                        while (n++ < (flags.width - prec - 1))
                            printf(" ");//write(1, " ", 1);
                    else
                        while (n++ < (flags.width - prec))
                            printf(" ");//write(1, " ", 1);
                    while (n++ < (flags.width - prec))
                        printf(" ");//write(1, " ", 1);
                    if (flags.justify == '!')
                        printf("%c", '-');
                    if (flags.justify == '+')
                        printf("%c", '+');
                    while (prec-- > intlen)
                        printf("%c", '0');
                    while (intlen--)
                        printf("%c", num[i++]);
                }
            }
    }

}

void	ft_write_int(st_flags flags)
{
    char *num;
    int n;
    int intlen;

    n = 0;
    num = flags.arg;
    intlen = ft_strlen(num);
    /*printf("intlen:%d\n", intlen);
    printf("width:%d\n", flags.width);
    printf("prec:%d\n", flags.prec);
    printf("num:%s<-\n", num);
    printf("dot:%d\n", flags.dot);*/
    if(flags.dot)
    {
        //if(flags.prec)
        if (!flags.prec && !flags.width)
        {
            while(n++ < (flags.width - intlen))
            { 
                printf(" ");//write(1, " ", 1);
            }
            n = 0;
            while (intlen-- && num[0] != '0')
                printf("%c", num[n++]);
        }
        else
            ft_int_prec_or_len(flags, num, intlen);
    }
    else
    {
        if (!flags.width && !flags.prec)
            while (n < intlen)
                printf("%c", num[n++]);//write(1, &num[n], 1);
        if (((flags.justify == '-' && flags.dot) || flags.justify != '-') && flags.width)
            n = ft_write_pos(flags, intlen);
        while (n < flags.width && flags.justify == '-')
        {
            if (n < intlen)
                printf("%c", num[n]);//write(1, &num[n], 1);
            ++n;
            if (n > intlen)
                printf(" ");//write(1, " ", 1);
        //write(1, "", 1);
        }
    }
}