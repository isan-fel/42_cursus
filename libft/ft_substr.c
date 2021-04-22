/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:21:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/22 19:30:36 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		array = (char *)malloc(sizeof(char));
		array[0] = '\0';
		return (array);
	}
	array = (char *)ft_calloc(sizeof(char) * (len + 1), sizeof(char));
	if (!array)
		return (NULL);
	while (len--)
	{
		array[i] = s[start];
		++start;
		++i;
	}
	return (array);
}
/*
#include <string.h>
int main ()
{
char *s;
s = ft_substr("tripouille", 0, 4200);
printf("%zu\n", ft_strlen(s));
printf("%zu\n",  ft_strlen("tripouille") + 1);
}*/
