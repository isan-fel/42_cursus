/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:35:04 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 19:04:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*void	*ft_memset(void *str, int c, size_t n)
{
	int i;

	i = 0;
	while (i <= n)
	{
		str[i] = c;
		++i;
	}
}*/

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*string;

	string = (unsigned char*)str;
	while (len-- > 0)
		*(string++) = (unsigned char)c;
	return (str);
}

int main()
{
	char source[]="hola caracola";
	printf("my func: %s\n", ft_memset(source, '$', 0));
	printf("C func: %s\n", memset(source, '$', 0));
}
