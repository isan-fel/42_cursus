/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:11:16 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 17:41:33 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	int			i;

	i = 0;
	src = s;
	while (n--)
	{
		if (src[i] == c)
			return ((char *) src + i);
		++i;
	}
	return (NULL);
}
