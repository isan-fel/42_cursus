/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:16:10 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/11 17:06:31 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strcat(char *dest, char *src)
{
	int n;
	int i;

	n = 0;
	while (true)
	{
		if (dest[n] == '\0')
		{
			i = 0;
			while (src[i] != '\0')
			{
				dest[n] = src[i];
				++i;
				++n;
			}
			break ;
		}
		++n;
	}
	dest[n] = '\0';
	return (dest);
}
