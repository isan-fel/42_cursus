/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:51:11 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 13:20:23 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_color(int z, t_program *program)
{
	double	percentage;

    percentage = percent(program->map.z_min, program->map.z_max, z);
	if (percentage < 0.2)
		return (0xc5e3be);
	else if (percentage < 0.5)
		return (0xe3ff00);
	else if (percentage < 0.8)
		return (0xffcc78);
	else
		return (0xfff8eb);
}

/*
** Get light for color. Result depends on point position.
** This function is needed to create linear gradient.
*/
/*
int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}*/

/*
** Get color. Result depends on point position.
** This function is needed to create linear gradient.
*/
/*
int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF,
					end.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}*/