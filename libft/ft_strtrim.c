/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:16:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 19:12:27 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findleft(char const *s1, char const *set)
{
	int	i;
	size_t n;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		//printf("entra al while");
		n = 0;
		while (set[n] != '\0')
		{
			if (set[n] == s1[i])
				break ;
			++n;
		}
		//printf("valor de n: %zu\n", n);
		if ( n == ft_strlen((char *)set))
			break ;
		++i;
	}
	//printf("valor de i: %d\n", i);
	return (i);
}

int	ft_findright(char const *s1, char const *set)
{
	int	j;
	int len;
	size_t n;

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
		if ( n == ft_strlen((char *)set))
			break ;
		--j;
	}
	//printf("valor de len: %d\n", len);
	//printf("valor de j: %d\n", j);
	return (len - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int len;
	
	size_t i = ft_findleft(s1, set);
	int j = ft_findright(s1, set);
	if (ft_strlen((char *)s1) == i)
		len = 0;
	else
		len = ft_strlen((char *)s1) - i - j;
	/*printf("valor de strlen: %zu\n", ft_strlen((char *)s1));
	printf("valor de len: %d\n", len);
	printf("valor de i: %zu\n", i);
	printf("valor de j: %d\n", j);	
	*/
	aux = (char *)malloc(sizeof(char) * len);
	if (!aux)
		return (0);
	//printf("cuanta memoria he reservado: %lu\n", ft_strlen((char *)s1) - i - j);
	s1 = (char *)s1 + i;
	//printf("s1 quitando parte izquierda: %s\n", s1);
	aux = ft_substr(s1, 0, len);
	aux[len + 1] = '\0';
 
	return (aux);
}
/*
int main ()
{
	char s1[] = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
	char s2[] = "Hello \t  Please\n Trim me !";
	int r_size = ft_strlen(s2);
	//char s1[] = "lorem ipsum dolor sit amet \n \t ";
	//char s1[] = "abbba";
	//char	set [] = "ab";
	char	set [] = " \n\t";
	printf("res trim:<<%s\n", ft_strtrim(s1, set));
	printf("len trim:%zu\n", ft_strlen(ft_strtrim(s1, set)));
	printf("len s2: %d\n", r_size);
}*/
