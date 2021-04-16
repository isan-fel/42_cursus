/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:06:49 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 16:39:08 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	if (to_find[n] == '\0')
		return (str);
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	while (n <= len)
	{
		i = 0;
		while (str[n + i] == to_find[i])
		{
			++i;
			if (to_find[i] == '\0' && (n + i) <= len)
				return (str + n);
		}
		++n;
	}
	return (0);
}
