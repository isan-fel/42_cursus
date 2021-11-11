void ft_draw_line(float x, float y, t_program *p)
{
    float   x_next;
    float   y_next;
    int     z;
    int     z1;
    int     color;
    
    //ft_window_oversize_control(program);
    //printf("coor z:%d ; %d", (int)y, (int)x);
    z = p->map.map[(int)y][(int)x];
    z1 = p->map.map[(int)p->map.y1][(int)p->map.x1];
    /*color condition*/
    if (p->map.own_color)
        color = p->map.map_color[(int)y][(int)x];
    else if (z || z1)
        color = 0xffcc78;
    else
        color = 0xdcfffc;
    if (p->map.reset)
        color = 0x000000;
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
            my_mlx_pixel_put(p, x, y, color);
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
                    ft_draw_line(x, y, p);}
            if (y < p->map.y_count - 1)
            {
                p->map.x1 = x;
                p->map.y1 = y + 1;
                ft_draw_line(x, y, p);
            }
        }
    }
}
