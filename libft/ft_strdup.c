/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:31:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 19:27:57 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!result)
		return (0);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
