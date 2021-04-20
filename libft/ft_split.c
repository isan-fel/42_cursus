/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:04:18 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/19 19:31:28 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_num(char const *s, char c)
{
	int	count;
	int	n;

	count = 0;
	n = 0;
	while (s[++n] != 0)
	{
		if (s[n] == c && s[n + 1] != c)
			++count;
	}
	if (count > 0)
		return (count + 1);
	return (0);
}

int	ft_wordlen(char const *str, char c)
{
	int	n;
	int	count;

	n = -1;
	count = 0;
	while (str[++n] != c)
	{
		if (str[n] == '\0')
			break ;
		++count;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		i;
	int		n;
	int		x;

	i = 0;
	n = -1;
	if (!s)
		return (NULL);
	table = malloc(sizeof(char *) * (ft_word_num(s, c) + 1));
	if (!table)
		return (NULL);
	while (s[++n] != 0)
	{
		if (s[n] != c)
		{
			x = ft_wordlen(s + n, c);
			table[i] = ft_substr(s, n, x);
			++i;
			n = n + x - 1;
		}
	}
	table[i] = NULL;
	return (table);
}
