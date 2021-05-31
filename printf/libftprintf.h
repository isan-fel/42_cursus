/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:17 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/31 15:35:34 by isan-fel         ###   ########.fr       */
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
	char    type;
	char	*arg;
}	st_flags;

void	ft_write_int(st_flags flags);
void	ft_write_char(st_flags flags);
int 	ft_count_arglen(st_flags flags);

#endif
