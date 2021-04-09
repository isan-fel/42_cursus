/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:08:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 22:32:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(unsigned int nb)
{
	int len;

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

char	*ft_writeneg(char *str, int numlen, unsigned int nb)
{
	str[0] = 45;
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
	return (str);
}

char	*ft_writepos(char *str, int numlen, int nb)
{
	str[numlen] = '\0';
	--numlen;
	while (numlen >= 0)
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
	return (str);
}

char	*ft_itoa(int n)
{
	int numlen;
	char *str;
	unsigned int	nc;

	str = "r";
	if (n < 0)
	{
		nc = n * -1;
		numlen = ft_intlen(nc) + 1;
		str = (char *)malloc(sizeof(char) * numlen);
		ft_writeneg(str, numlen, nc);
	}
	else
	{
		numlen = ft_intlen(n);
		str = (char *)malloc(sizeof(char) * numlen);
		ft_writepos(str, numlen, n);
	}
	return (str);
}

int main()
{
	int num = 456;

	printf("%s", ft_itoa(num));
}
