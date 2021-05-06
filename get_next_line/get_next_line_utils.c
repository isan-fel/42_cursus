/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:25 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/06 18:41:24 by isan-fel         ###   ########.fr       */
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

int    ft_intchr(const char *s, int c)
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

/*strchr mod -> add +1 in return to avoid \n for get_next_line*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		++i;
	}
	return (NULL);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		n;
	int		i;

	n = 0;
	if (s1 && s2)
	{
		str = ft_calloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1, 1);
		if (!str)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
			str[n++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[n++] = s2[i++];
		return (str);
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		--i;
	}
	return ((char *) NULL);
}

void	ft_strdel(char **as)
{
	if (!as)
		;
	else
	{
		free(*as);
		*as = NULL;
	}
}

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
