/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:13:24 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 17:46:23 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		n;
	int		i;

	n = 0;
	if (s1 && s2)
	{
		str = ft_calloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1, 1);
		if (!str)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
			str[n++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[n++] = s2[i++];
		return (str);
	}
	return (NULL);
}
