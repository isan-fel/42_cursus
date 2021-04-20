/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:20:53 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 17:43:53 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (const unsigned char) c)
			return (dest + i + 1);
		++i;
	}
	return (NULL);
}
