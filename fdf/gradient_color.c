/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:51:11 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/02 20:06:48 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_convert_hexa(char a, char b)
{
	int		result;
	char	*hexa;
	int		i;
	int		x;
	int		r;

	a = ft_tolower(a);
	b = ft_tolower(b);
	hexa = "0123456789abcdef";
	x = -1;
	i = -1;
	r = -1;
	while (hexa[++r] != '\0')
	{
		if (hexa[r] == a)
			i = r;
		if (hexa[r] == b)
			x = r;
	}
	if ((x < 0) || (i < 0))
		err_ctrl("Error: wrong color format\n", 3);
	result = (i * 16) + (x * 1);
	return (result);
}

int	ft_set_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if ((str[0] != '0' || str[1] != 'x') || (
			(str[0] == '0' && str[1] == 'x') && (str[2] == '\0')))
		err_ctrl("Error: wrong color format\n", 3);
	r = ft_convert_hexa(str[2], str[3]);
	if (ft_strlen(str) == 4)
	{
		g = ft_convert_hexa('0', '0');
		b = ft_convert_hexa('0', '0');
	}
	else if (ft_strlen(str) == 6)
	{
		g = ft_convert_hexa(str[4], str[5]);
		b = ft_convert_hexa('0', '0');
	}
	else
	{
		g = ft_convert_hexa(str[4], str[5]);
		b = ft_convert_hexa(str[6], str[7]);
	}
	return (r << 16 | g << 8 | b);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
        return(1.0);
    return (placement / distance);
}

/*
** Get color from default palette. Color depends on altitude
*/

int	get_color(int z, int z1, t_program *program)
{
	double	percentage;

    if (z)
		percentage = percent(program->map.z_min, program->map.z_max, z);
	else if (z1)
		percentage = percent(program->map.z_min, program->map.z_max, z1);
	if (percentage < 0.2)
		return (0xc5e3be);
	else if (percentage < 0.5)
		return (0xe3ff00);
	else if (percentage < 0.8)
		return (0xffcc78);
	else
		return (0xfff8eb);
}