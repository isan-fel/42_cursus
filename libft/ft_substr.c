/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:21:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/26 13:23:42 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_exact_len(char const *s, size_t len)
{
	size_t	array_len;

	array_len = ft_strlen(s);
	if (array_len <= len)
		return (array_len);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;
	size_t			exact_len;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		array = (char *)malloc(sizeof(char));
		array[0] = '\0';
		return (array);
	}
	exact_len = ft_exact_len(s, len);
	array = (char *)ft_calloc(sizeof(char) * (exact_len + 1), sizeof(char));
	if (!array)
		return (NULL);
	while (exact_len--)
	{
		array[i] = s[start];
		++start;
		++i;
	}
	return (array);
}
