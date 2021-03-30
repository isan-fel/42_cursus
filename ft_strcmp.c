/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:18:09 by isan-fel          #+#    #+#             */
/*   Updated: 2021/03/15 10:47:08 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	if (s1[n] == '\0' && s2[n] == '\0')
		return (0);
	while (s1[n] != '\0')
	{
		if (s1[n] < s2[n])
			return (s1[n] - s2[n]);
		if (s1[n] > s2[n])
			return (s1[n] - s2[n]);
		++n;
	}
	if (s2[n] != '\0')
		return (s1[n] - s2[n]);
	return (0);
}
