/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:02 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 18:26:57 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float   ft_max_int(float i, float j)
{
    if (i > j)
        return(i);
    return(j);
}

float   ft_mod_int(float i)
{
    if (i < 0)
        return(i * -1);
    return(i);
}

void    my_mlx_pixel_put(t_program *p, int x, int y)
{
	char	*dst;

	dst = p->img.pixels + (y * p->img.line_size + x * (p->img.bits_per_pixel / 8));
	*(unsigned int*)dst = p->map.color;
}

void ft_draw_line(float x, float y, t_program *p)
{
    float   x_next;
    float   y_next;
    int     z;
    int     z1;
    //int     color;
    
    //ft_window_oversize_control(program);
    //printf("coor z:%d ; %d", (int)y, (int)x);
    z = p->map.map[(int)y][(int)x];
    z1 = p->map.map[(int)p->map.y1][(int)p->map.x1];
    /*color condition*/
    if (p->map.own_color)
        p->map.color = p->map.map_color[(int)y][(int)x];
    else if (z || z1)
        p->map.color = 0xffcc78;
    else
        p->map.color = 0xdcfffc;
    if (p->map.reset)
        p->map.color = 0x000000;
    //printf("color:%x\n", color);
    /*change altitude scale*/
    z *= p->map.alt_zoom;
    z1 *= p->map.alt_zoom;
    /*for make zoom to the grid*/
    x *= p->map.zoom;
    y *= p->map.zoom;
    p->map.x1 *= p->map.zoom;
    p->map.y1 *= p->map.zoom;
    /*change coordinates for isometric view*/
    x = (x - y) * cos(0.8);
    y = (x + y) * sin(0.8) - z;
    p->map.x1 = (p->map.x1 - p->map.y1) * cos(0.8);
    p->map.y1 = (p->map.x1 + p->map.y1) * sin(0.8) - z1;
    /*shift to avoid cut with edge*/
    x += p->map.shift;
    y += p->map.shift/4;
    p->map.x1 += p->map.shift;
    p->map.y1 += p->map.shift/4; 
    x_next = (p->map.x1 - x) / ft_max_int(ft_mod_int(p->map.x1 - x), ft_mod_int(p->map.y1 - y));
    y_next = (p->map.y1 - y) / ft_max_int(ft_mod_int(p->map.x1 - x), ft_mod_int(p->map.y1 - y));
    while ((int)(x - p->map.x1) || (int)(y - p->map.y1))
    {
        if ((x > 0 && x < p->window_x_size) && (y > 0 && y < p->window_y_size))
            my_mlx_pixel_put(p, x, y);
        x += x_next;
        y += y_next;
    }
}

void ft_trace_pixel(t_program *p, int reset)
{
    int x;
    int y;

    p->map.reset = reset;
    y = -1;
    while (++y < p->map.y_count)
    {
        x = -1;
        while (++x < p->map.x_count)
        {
            if (x < p->map.x_count - 1)
            {   p->map.x1 = x + 1;
                    p->map.y1 = y;
                    ft_draw_line(x, y, p);
            }
            if (y < p->map.y_count - 1)
            {
                p->map.x1 = x;
                p->map.y1 = y + 1;
                ft_draw_line(x, y, p);
            }
        }
    }
}