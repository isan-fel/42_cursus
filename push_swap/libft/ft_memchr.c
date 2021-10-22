/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:11:16 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/22 12:45:03 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	size_t		i;

	i = 0;
	src = (const char *)s;
	while (n--)
	{
		if (src[i] == (char)c)
			return ((void *)s + i);
		++i;
	}
	return (NULL);
}
