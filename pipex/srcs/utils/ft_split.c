/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:04:18 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 18:06:23 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	ft_word_num(char const *s, char c)
{
	int	count;
	int	n;

	count = 0;
	n = 0;
	if (s[n] != c)
		++count;
	while (s[++n] != 0)
	{
		if (s[n] == c && s[n + 1] != c)
			++count;
	}
	return (count);
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

	i = 0;
	n = -1;
	if (!s || !*s)
	{
		table = malloc(sizeof(char *) * 1);
		table[i] = NULL;
		return (table);
	}
	table = ft_calloc(sizeof(char *) * (ft_word_num(s, c) + 1), 1);
	if (!table)
		return (NULL);
	while (s[++n] != 0)
	{
		if (s[n] != c)
		{
			table[i++] = ft_substr(s, n, ft_wordlen(s + n, c));
			n = n + ft_wordlen(s + n, c) - 1;
		}
	}
	return (table);
}
