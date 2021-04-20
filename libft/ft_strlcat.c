/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:15:18 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/20 12:45:19 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	n;

	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dest);
	i = dest_len;
	n = 0;
	if (destsize < dest_len)
		return (src_len + destsize);
	while (src[n] != 0 && i < destsize - 1)
		dest[i++] = src[n++];
	dest[i] = '\0';
	return (src_len + dest_len);
}
