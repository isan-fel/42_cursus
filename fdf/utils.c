/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:02:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 20:10:31 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float   max_i(float i, float j)
{
    if (i > j)
        return(i);
    return(j);
}

float   mod_int(float i)
{
    if (i < 0)
        return(i * -1);
    return(i);
}

int    ft_cords(t_program *p, int z1)
{
    p->m.x1 *= p->m.zoom;
    p->m.y1 *= p->m.zoom;
    p->m.x1 = (p->m.x1 - p->m.y1) * cos(0.8);
    z1 *= p->m.alt_zoom;
    p->m.y1 = (p->m.x1 + p->m.y1) * sin(0.8) - z1;
    p->m.x1 += p->m.shift;
    p->m.y1 += p->m.shift/4;
    return (z1);
}

int ft_color(t_program *p, int z, int z1)
{
    if (z || z1)
        p->m.color = 0xffcc78;
    else
        p->m.color = 0xdcfffc;
    if (p->m.reset)
        p->m.color = 0x000000;
    z *= p->m.alt_zoom;
    return (z);
}

void    ft_map_color(t_program *p, float x, float y)
{
    if (p->m.own_color)
        p->m.color = p->m.map_color[(int)y][(int)x];
}