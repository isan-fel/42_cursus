/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:20:53 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/08 18:53:30 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;
	const char	*s;

	s = src;
	d = dest;
	while (n--)
	{
		if (n == 0)
		{
			*d++=*s++;	
			break;
		}
		*d++ = *s++;
		if (*s == c)
		{
			*d++ = *s++;
			break;
		}
		
	}
	return (dest);
}
