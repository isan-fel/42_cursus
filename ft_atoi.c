/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:12:03 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/18 11:26:43 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str)
{
	int atoi;
	int	n;
	int	negative_count;

	n = 0;
	negative_count = 1;
	atoi = 0;
	while ((str[n] == 32) || (str[n] > 8 && str[n] < 14))
		++n;
	while (str[n] == 43 || str[n] == 45)
	{
		if (str[n] == 45)
			negative_count = negative_count * (-1);
		++n;
	}
	while (str[n] > 47 && str[n] < 58)
	{
		atoi = atoi * 10 + str[n] - 48;
		++n;
	}
	return (atoi * negative_count);
}
