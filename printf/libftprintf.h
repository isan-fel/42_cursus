/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:17 by isan-fel          #+#    #+#             */
/*   Updated: 2021/06/08 12:10:55 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct flags_struct
{
	char	justify;
	int		dot;
    int		zero;
	int		asterisk;
    int		width;
	int		prec;
	char    type;
	char	*arg;
}	st_flags;

int		ft_printf(const char *str, ...);
void	ft_write_int(st_flags flags);
int		ft_write_char(st_flags flags);
int 	ft_count_arglen(st_flags flags, int len);
void	ft_write_string(st_flags flags);
char	*ft_uint_itoa(unsigned int n);
void	ft_hex(unsigned int n, st_flags flags);
int		ft_hexlen(unsigned int n, st_flags flags);

#endif
