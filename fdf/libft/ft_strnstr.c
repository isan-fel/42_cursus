/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:06:49 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/22 13:05:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	if (to_find[n] == '\0')
		return ((char *)str);
	if (ft_strlen(str) < ft_strlen(to_find))
		return (NULL);
	while (n <= len && str[n] != '\0')
	{
		i = 0;
		while (str[n + i] == to_find[i])
		{
			if (to_find[i + 1] == '\0' && (n + i) < len)
				return ((char *)str + n);
			++i;
		}
		++n;
	}
	return (NULL);
}
