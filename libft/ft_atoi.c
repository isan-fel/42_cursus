/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:12:03 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 17:41:01 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	unsigned long long	num;
	int					n;
	int					negative_count;

	n = 0;
	num = 0;
	negative_count = 1;
	while ((str[n] == 32) || (str[n] > 8 && str[n] < 14))
		++n;
	if (str[n] == 43 || str[n] == 45)
	{
		if (str[n] == 45)
			negative_count = -1;
		++n;
	}
	while (str[n] > 47 && str[n] < 58)
	{
		num = num * 10 + str[n] - 48;
		++n;
	}
	if (num > 9223372036854775807 && negative_count == 1)
		return (-1);
	if (num - 1 > 9223372036854775807 && negative_count == -1)
		return (0);
	return (num * negative_count);
}
