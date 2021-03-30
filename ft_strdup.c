/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:31:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/17 14:12:36 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;
	
	n = 0;
	while (str[n] != '\0')
	{
		++n;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	char *result;
	int src_len;
	int i;

	src_len = ft_strlen(src);
	result = (char *) malloc(sizeof(char)*src_len);
	//*src = *result;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

int main ()
{
	char *source = "hola";
	//char *result;
	
	//result = ft_strdup(source);
	printf("%s\n", ft_strdup(source));
}
