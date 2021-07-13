/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:49:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/07/13 16:04:06 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

int	ft_intlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb >= 1)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

char	*ft_char(char c_antes)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c_antes;
	str[1] = '\0';
	return (str);
}

t_flags	*ft_initiate_flags(t_flags *flags)
{
	flags->justify = '0';
	flags->dot = 0;
	flags->zero = 0;
	flags->asterisk = 0;
	flags->width = 0;
	flags->prec = 0;
	flags->type = '%';
	flags->arg = NULL;
	flags->neg_prec = 0;
	return (flags);
}

char	*ft_strdup_string_printf(char *src)
{
	char	*result;
	int		i;

	i = 0;
	if (!src)
		src = "(null)";
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
