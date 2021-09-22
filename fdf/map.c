/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:02 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/09 18:31:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_max_int(float i, float j)
{
    if (i > j)
        return(i);
    return(j);
}

float ft_mod_int(float i)
{
    if (i < 0)
        return(i * -1);
    return(i);
}

void ft_draw_line(float x, float y, float x1, float y1, t_program *program, t_map *map)
{
    float x_next;
    float y_next;
    int z;
    int z1;
    int color;
    
    //printf("coor z:%d ; %d", (int)y, (int)x);
    z = map->map[(int)y][(int)x];
    z1 = map->map[(int)y1][(int)x1];
    /*if (z)
        color = 0xe80c0c;
    else
        color = 0xffffff;*/
    /*for make zoom to the grid*/
    map->zoom = 25;
    x *= map->zoom;
    y *= map->zoom;
    x1 *= map->zoom;
    y1 *= map->zoom;
    /*change coordinates for isometric view*/
    x = (x - y) * cos(0.8);
    y = (x + y) * sin(0.8) - z;
    x1 = (x1 - y1) * cos(0.8);
    y1 = (x1 + y1) * sin(0.8) - z1;
    /*shift to avoid cut with edge*/
    x += 180;
    y += 180;
    x1 += 180;
    y1 += 180;
    x_next = (x1 - x) / ft_max_int(ft_mod_int(x1 - x), ft_mod_int(y1 - y));
    y_next = (y1 - y) / ft_max_int(ft_mod_int(x1 - x), ft_mod_int(y1 - y));
    //printf("x_next:%f ; %f", x_next, y_next);
    while ((int)(x - x1) || (int)(y - y1))
    {
        //mlx_pixel_put(program->mlx, program->window, x, y, color);
        if (z || z1)
            mlx_pixel_put(program->mlx, program->window, x, y, 0xe80c0c);
        else
            mlx_pixel_put(program->mlx, program->window, x, y, 0xffffff);
        x += x_next;
        y += y_next;
    }

}

void ft_trace_pixel(t_program *program, t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->y_count)
    {
        x = 0;
        while (x < map->x_count)
        {
            if (x < map->x_count - 1)
                ft_draw_line(x, y, x + 1, y, program, map);
            if (y < map->y_count - 1)
                ft_draw_line(x, y, x, y + 1, program, map);
            ++x;
        }
        ++y;
    }
}