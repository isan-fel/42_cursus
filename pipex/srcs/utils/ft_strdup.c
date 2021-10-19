/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:31:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 17:29:38 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!result)
		return (NULL);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
