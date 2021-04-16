/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:21:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 19:35:54 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
		return ((char *)malloc(sizeof(char)*0));
	array = (char *)ft_calloc(sizeof(char) * len + 1, 1);
	if (!array)
		return (0);
	while (len--)
	{
		array[i] = s[start];
		++start;
		++i;
	}
	return (array);
}

int main ()
{
	char *str = "i just want this part #############";
	size_t size = 20;
	printf("%s", ft_substr(str, 5, size));
	/*
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);
*/
}
