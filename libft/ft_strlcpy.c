/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:47:20 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/20 12:46:14 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!src || !dest)
		return (0);
	len = ft_strlen((char *) src);
	if (destsize == 0)
		return (len);
	while (src[i] != '\0' && i < destsize - 1)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}
