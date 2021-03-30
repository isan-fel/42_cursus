/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:35:36 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/02 17:04:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_num(int nb)
{
	if (nb > 9)
	{
		ft_num(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putnbr(int nb)
{
	unsigned int nc;

	if (nb < 0)
	{
		nc = nb * (-1);
		ft_putchar(45);
		if (nc == 2147483648)
		{
			ft_putchar(2 + 48);
			nc = 147483648;
			ft_num(nc);
		}
		else
		{
			ft_num(nc);
		}
	}
	else
	{
		if (nb <= 2147483647)
			ft_num(nb);
	}
}
