/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:10:55 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 17:23:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	i;

	n = 0;
	if (to_find[n] == '\0')
		return (str);
	while (str[n] != '\0')
	{
		i = 0;
		while (str[n + i] == to_find[i])
		{
			++i;
			if (to_find[i] == '\0')
				return (str + n);
		}
		++n;
	}
	return (NULL);
}
