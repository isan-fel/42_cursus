/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:17 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/06 17:24:18 by isan-fel         ###   ########.fr       */
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


int			ft_intlen(unsigned int nb);
char		*ft_char(char c_antes);
st_flags	ft_initiate_flags(void);
int			ft_printf(const char *str, ...);
int			ft_justify(char str, st_flags *flags, int n);
int			ft_zero(char str, st_flags *flags, int n);
void		ft_width(const char *str, int  n, st_flags *flags);
int			ft_asterik(va_list param, const char *str, int n, st_flags *flags);
void		ft_prec(const char *str, int  n, st_flags *flags);
int			ft_dot_logic(va_list param, const char *str, st_flags *flags, int n);
int			ft_save_every_flag(va_list param, const char *str, int n, st_flags *flags);
void		ft_write_int(st_flags flags);
void    	ft_int_prec_or_len(st_flags flags, char *num, int intlen);
int			ft_write_char(st_flags flags);
int 		ft_count_arglen(st_flags flags, int len);
void		ft_write_string(st_flags flags);
char		*ft_uint_itoa(unsigned int n);
char 		*ft_write_hex(unsigned int n, st_flags flags);
char		*ft_write_pointer(unsigned long long n);

#endif
