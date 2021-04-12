/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:21:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/12 13:38:59 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;

	i = 0;
	array = (char *)malloc(sizeof(char) * len);
	while (start <= len)
	{
		array[i] = s[start];
		++start;
		++i;
	}
	return (array);
}
