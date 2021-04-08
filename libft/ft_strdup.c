/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:31:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/08 18:42:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*result;
	size_t	src_len;
	int		i;

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
