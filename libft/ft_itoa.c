/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:08:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 17:59:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int nb)
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

static char	*ft_write(char *str, int numlen, unsigned int nb, int flag_neg)
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

char	*ft_itoa(int n)
{
	int				numlen;
	char			*str;
	unsigned int	nc;

	if (n < 0)
	{
		nc = n * -1;
		numlen = ft_intlen(nc) + 1;
		str = (char *)malloc(sizeof(char) * numlen + 1);
		if (!str)
			return (0);
		str[0] = 45;
		ft_write(str, numlen, nc, 1);
	}
	else
	{
		nc = n;
		numlen = ft_intlen(nc);
		str = (char *)malloc(sizeof(char) * numlen + 1);
		if (!str)
			return (0);
		ft_write(str, numlen, nc, 0);
	}
	return (str);
}
