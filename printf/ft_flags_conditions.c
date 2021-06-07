/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:13:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/06/07 19:01:59 by isan-fel         ###   ########.fr       */
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
            //printf("entra");
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
        if (flags.width == 0)
        {
            while (n < intlen && flags.dot == 0 && flags.prec)
            {
                printf("%c", num[n]);//write(1, &num[n], 1);
                ++n;
            }
        }
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

void    ft_string_prec_or_len(st_flags flags, char *str, int len)
{
    int n;
    int prec;

    n = 0;
    prec = flags.prec;
    if (prec <= len)
    {
        while ((n++ < (flags.width - prec)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (prec--)
            printf("%c", str[n++]);
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (len--)
            printf("%c", str[n++]);
    }
    while (n++ < flags.width && flags.justify == '-')
        printf(" ");//write(1, " ", 1);
}

void ft_write_string(st_flags flags)
{
    char *str;
    int n;
    int len;

    n = 0;
    str = flags.arg;
    len = ft_strlen(str);
    if (flags.dot)
    {
        if (flags.prec)
        {
            //printf("entra aqui");
            ft_string_prec_or_len(flags, str, len);
        }
        else
        {
            //printf("width:%d", flags.width);
            while (n++ < flags.width)
                printf(" ");//write(1, " ", 1);
        }
    }
    else
    {
        while ((n++ < (flags.width - len)) && flags.justify != '-')
            printf(" ");//write(1, " ", 1);
        n = 0;
        while (str[n] != '\0')
        {
            printf("%c", str[n]);
            ++n;
        }
        while (n++ < flags.width && flags.justify == '-')
            printf(" ");//write(1, " ", 1); 
    }
}

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
    if (flags.type == 'd' || flags.type == 'i')
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