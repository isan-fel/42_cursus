/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:31:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/30 19:19:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		++n;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int	src_len;
	int	i;

	i = 0;
	src_len = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * src_len + 1);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
