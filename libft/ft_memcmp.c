/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:06:47 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/08 18:55:17 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*source1;
	const char	*source2;
	size_t		i;

	i = 0;
	source1 = s1;
	source2 = s2;
	if (*source1 == '\0' && *source2 == '\0')
		return (0);
	while (i < n)
	{
		if (source1[i] != '\0' || source2[i] != '\0')
		{
			//if (source1[i] < source2[i])
				return (source1[i] - source2[i]);
		/*	if (source1[i] > source2[i])
				return (source1[i] - source2[i]);*/
		}
		/*else
			return (0);*/
		++i;	
	}
	return (0);
}
