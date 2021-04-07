/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:23:18 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/15 12:10:47 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	x;

	i = 0;
	while (true)
	{
		if (dest[i] == '\0')
		{
			x = 0;
			while (src[x] != '\0' && x < nb)
			{
				dest[i] = src[x];
				++i;
				++x;
			}
			break ;
		}
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
