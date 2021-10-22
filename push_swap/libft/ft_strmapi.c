/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:51:19 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 17:46:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[++i] != 0)
		str[i] = f(i, s[i]);
	return (str);
}
