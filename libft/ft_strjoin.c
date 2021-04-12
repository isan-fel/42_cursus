/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:13:24 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/12 13:37:11 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*

#include <stdbool.h>

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		++n;
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	i;

	n = 0;
	while (true)
	{
		if (dest[n] == '\0')
		{
			i = 0;
			while (src[i] != '\0')
			{
				dest[n] = src[i];
				++i;
				++n;
			}
			break ;
		}
		++n;
	}
	dest[n] = '\0';
	return (dest);
}*/

size_t	ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot_len;
	char	*tot_str;
	tot_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	tot_str = (char *)malloc(sizeof(char) * tot_len);
	tot_str = ft_strcat((char *)s1, (char *)s2);
	return (tot_str);
}
