/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:28 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/12 13:00:05 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_num(int nb, int fd)
{
	if (nb > 9)
	{
		ft_num(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nc;

	if (nb < 0)
	{
		nc = nb * (-1);
		ft_putchar_fd(45, fd);
		if (nc == 2147483648)
		{
			ft_putchar_fd(2 + 48, fd);
			nb = 147483648;
			ft_num(nb, fd);
		}
		else
		{
			ft_num(nc, fd);
		}
	}
	else
	{
		if (nb <= 2147483647)
			ft_num(nb, fd);
	}
}
