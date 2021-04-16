/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:19:44 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/15 16:46:52 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc (size_t num, size_t size)
{
	void	*str;

	str = malloc(size * num);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
