/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:17 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 16:12:28 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define FLAGS "cspdiuxX%"

typedef struct s_flags_struct
{
	char	justify;
	int		dot;
	int		zero;
	int		asterisk;
	int		width;
	int		prec;
	char	type;
	char	*arg;
	int		neg_prec;
	int		len;
}	t_flags;

int		ft_intlen(unsigned int nb);
char	*ft_char(char c_antes);
t_flags	*ft_initiate_flags(t_flags *flags);
char	*ft_strdup_string_printf(char *src);
int		ft_printf(const char *str, ...);
int		ft_justify(char str, t_flags *flags);
int		ft_zero(char str, t_flags *flags);
void	ft_width(const char *str, int n, t_flags *flags);
int		ft_asterik(va_list param, const char *str, int n, t_flags *flags);
int		ft_prec(const char *str, int n, t_flags *flags);
int		ft_dot_logic(va_list param, const char *str, t_flags *flags, int n);
int		save_every_flag(va_list param, const char *str, int n, t_flags *flags);
void	ft_write_int(t_flags *flags);
void	ft_int_prec_or_len(t_flags *flags, char *num, int intlen);
int		ft_write_char(t_flags *flags);
void	ft_write_string(t_flags *flags);
char	*ft_uint_itoa(unsigned int n);
char	*ft_write_hex(unsigned int n, t_flags flags);
char	*ft_write_pointer(unsigned long long n);
void	ft_neg_prec_morethan_width(t_flags *flags, int intlen);
void	negprec_len(t_flags *flags, char *num, int intlen, int i);
void	negprec_mt_wlen(t_flags *flags, char *num, int intlen, int i);

#endif
