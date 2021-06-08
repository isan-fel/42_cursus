/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan <isan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:08:41 by user42            #+#    #+#             */
/*   Updated: 2021/06/08 10:30:41 by isan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb >= 1)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

static char	*ft_write(char *str, int numlen, long nb, int flag_neg)
{
	str[numlen] = '\0';
	--numlen;
	while (numlen > 0)
	{
		if (nb < 9)
			str[numlen] = ((nb % 10) + 48);
		else
		{
			str[numlen] = ((nb % 10) + 48);
			nb = nb / 10;
		}
		--numlen;
	}
	if (flag_neg == 0)
		str[numlen] = ((nb % 10) + 48);
	return (str);
}

char	*ft_uint_itoa(unsigned int n)
{
	int				numlen;
	char			*str;
	long	nc;

	if (n < 0)
	{
		nc = n * -1;
		numlen = ft_intlen(nc) + 1;
		str = (char *)malloc(sizeof(char) * numlen + 1);
		if (!str)
			return (NULL);
		str[0] = 45;
		ft_write(str, numlen, nc, 1);
	}
	else
	{
		nc = n;
		numlen = ft_intlen(nc);
		str = (char *)malloc(sizeof(char) * numlen + 1);
		if (!str)
			return (NULL);
		ft_write(str, numlen, nc, 0);
	}
	return (str);
}
