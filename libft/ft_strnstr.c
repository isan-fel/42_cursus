/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:06:49 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/13 18:26:01 by isan-fel         ###   ########.fr       */
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
/*
#include <string.h>
int main ()
{
	char str[]="lorem ipsum dolor sit amet";
	char find[]="dolor";

	printf("%s\n", ft_strnstr(str, find, 15));
	printf("%s\n", strnstr(str, find, 15));
}*/
