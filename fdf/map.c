/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:02 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 20:23:03 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_program *p, int x, int y)
{
	char	*dst;

	dst = p->i.px + (y * p->i.l_sz + x * (p->i.bxpx / 8));
	*(unsigned int*)dst = p->m.color;
}

void ft_draw_line(float x, float y, t_program *p)
{
    float   x_next;
    float   y_next;
    int     z;
    int     z1;
    
    z = p->m.map[(int)y][(int)x];
    z1 = p->m.map[(int)p->m.y1][(int)p->m.x1];
    z = ft_color(p, z, z1);
    ft_map_color(p, x, y);
    x *= p->m.zoom;
    y *= p->m.zoom;
    x = (x - y) * cos(0.8);
    y = (x + y) * sin(0.8) - z;
    x += p->m.shift;
    y += p->m.shift/4;
    z1 = ft_cords(p, z1); 
    x_next = (p->m.x1 - x) / max_i(mod_int(p->m.x1 - x), mod_int(p->m.y1 - y));
    y_next = (p->m.y1 - y) / max_i(mod_int(p->m.x1 - x), mod_int(p->m.y1 - y));
    while ((int)(x - p->m.x1) || (int)(y - p->m.y1))
    {
        if ((x > 0 && x < p->win_x_size) && (y > 0 && y < p->win_y_size))
            my_mlx_pixel_put(p, x, y);
        x += x_next;
        y += y_next;
    }
}

void ft_trace_pixel(t_program *p, int reset)
{
    int x;
    int y;

    p->m.reset = reset;
    y = -1;
    while (++y < p->m.y_count)
    {
        x = -1;
        while (++x < p->m.x_count)
        {
            if (x < p->m.x_count - 1)
            {   
                p->m.x1 = x + 1;
                p->m.y1 = y;
                ft_draw_line(x, y, p);
            }
            if (y < p->m.y_count - 1)
            {
                p->m.x1 = x;
                p->m.y1 = y + 1;
                ft_draw_line(x, y, p);
            }
        }
    }
}