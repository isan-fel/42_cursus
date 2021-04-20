/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:16:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 19:35:45 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findleft(char const *s1, char const *set)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		n = 0;
		while (set[n] != '\0')
		{
			if (set[n] == s1[i])
				break ;
			++n;
		}
		if (n == ft_strlen((char *)set))
			break ;
		++i;
	}
	return (i);
}

int	ft_findright(char const *s1, char const *set)
{
	int		j;
	int		len;
	size_t	n;

	len = ft_strlen((char *) s1);
	if (len == 0)
		return (0);
	j = len - 1;
	n = 0;
	while (j >= 0)
	{
		n = 0;
		while (set[n] != '\0')
		{
			if (set[n] == s1[j])
				break ;
			++n;
		}
		if (n == ft_strlen((char *)set))
			break ;
		--j;
	}
	return (len - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int		len;
	size_t	i;
	int		j;

	j = ft_findright(s1, set);
	i = ft_findleft(s1, set);
	if (!s1)
		return (NULL);
	if (ft_strlen((char *)s1) == i)
		len = 0;
	else
		len = ft_strlen((char *)s1) - i - j;
	aux = (char *)malloc(sizeof(char) * len);
	if (!aux)
		return (NULL);
	s1 = (char *)s1 + i;
	aux = ft_substr(s1, 0, len + 1);
	return (aux);
}
