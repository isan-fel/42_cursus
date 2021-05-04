/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:25 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/29 18:19:39 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		++n;
	return (n);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*aux;

	aux = str;
	while (n-- > 0)
		*(aux++) = c;
	return (str);
}

void	ft_bzero(void *str, size_t nbyte)
{
	ft_memset(str, '\0', nbyte);
}

void	*ft_calloc (size_t num, size_t size)
{
	void	*str;

	str = malloc(size * num);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
/*strchr mod*/
int    ft_strchr(const char *s, int c)
{
        size_t  i;

        i = 0;
        while (i < ft_strlen(s) + 1)
        {
                if (s[i] == (char)c)
                        return (i);
                ++i;
        }
        return (0);
}

/*SPLIT*/
/*
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

size_t	ft_exact_len(char const *s, size_t len)
{
	size_t	array_len;

	array_len = ft_strlen(s);
	if (array_len <= len)
		return (array_len);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;
	size_t			exact_len;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		array = (char *)malloc(sizeof(char));
		array[0] = '\0';
		return (array);
	}
	exact_len = ft_exact_len(s, len);
	array = (char *)ft_calloc(sizeof(char) * (exact_len + 1), sizeof(char));
	if (!array)
		return (NULL);
	while (exact_len--)
	{
		array[i] = s[start];
		++start;
		++i;
	}
	return (array);
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
}*/
