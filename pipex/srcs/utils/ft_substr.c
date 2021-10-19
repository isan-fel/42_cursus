/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:21:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 18:06:52 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*aux;

	aux = str;
	while (n-- > 0)
		*(aux++) = c;
	return (str);
}

void	ft_bzero(void *str, size_t nbyte)
{
	ft_memset(str, '\0', nbyte);
}

void	*ft_calloc (size_t num, size_t size)
{
	void	*str;

	str = malloc(size * num);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}

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
