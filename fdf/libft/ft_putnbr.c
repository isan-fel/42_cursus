/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:35:36 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 11:58:45 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_num(int nb)
{
	if (nb > 9)
	{
		ft_num(nb / 10);
		ft_putchar_fd(nb % 10 + 48, 1);
	}
	else
		ft_putchar_fd(nb + 48, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nc;

	if (nb < 0)
	{
		nc = nb * (-1);
		ft_putchar_fd(45, 1);
		if (nc == 2147483648)
		{
			ft_putchar_fd(2 + 48, 1);
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
