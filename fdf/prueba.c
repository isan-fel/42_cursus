void ft_draw_line(t_program *program, int reset)
{
    float x_next;
    float y_next;
    /*int z;
    int z1;*/
    int color;
    
    //ft_window_oversize_control(program);
    //printf("coor z:%d ; %d", (int)y, (int)x);
    /*z = program->map.map[(int)y][(int)x];
    z1 = program->map.map[(int)y1][(int)x1];*/
    /*color condition*/
    if (program->map.own_color)
        color = program->map.map_color[(int)program->cords.y][(int)program->cords.x];
    else if (program->cords.z || program->cords.z1)
        //color = get_color(z,  z1, program);
        color = 0xffcc78;
    else
        color = 0xdcfffc;
    if (reset)
        color = 0x000000;
    //printf("color:%x\n", color);
    /*change altitude scale*/
    program->cords.z *= program->map.alt_zoom;
    program->cords.z1 *= program->map.alt_zoom;
    /*for make zoom to the grid*/
    program->cords.x *= program->map.zoom;
    program->cords.y *= program->map.zoom;
    program->cords.x1 *= program->map.zoom;
    program->cords.y1 *= program->map.zoom;
    /*change coordinates for isometric view*/
    program->cords.x = (program->cords.x - program->cords.y) * cos(0.8);
    program->cords.y = (program->cords.x + program->cords.y) * sin(0.8) - program->cords.z;
    program->cords.x1 = (program->cords.x1 - program->cords.y1) * cos(0.8);
    program->cords.y1 = (program->cords.x1 + program->cords.y1) * sin(0.8) - program->cords.z1;
    /*shift to avoid cut with edge*/
    program->cords.x += program->map.shift;
    program->cords.y += program->map.shift/4;
    program->cords.x1 += program->map.shift;
    program->cords.y1 += program->map.shift/4; 
    x_next = (program->cords.x1 - program->cords.x) / ft_max_int(ft_mod_int(program->cords.x1 - program->cords.x), ft_mod_int(program->cords.y1 - program->cords.y));
    y_next = (program->cords.y1 - program->cords.y) / ft_max_int(ft_mod_int(program->cords.x1 - program->cords.x), ft_mod_int(program->cords.y1 - program->cords.y));
    //printf("x_next:%f ; %f", x_next, y_next);
    /*if (z != z1)
	{
		isome.c1 = x - x1;
		isome.c2 = y - y1;
		isome.hipo = isome.c1 * isome.c1 + isome.c2 * isome.c2;
	}*/
    while ((int)(program->cords.x - program->cords.x1) || (int)(program->cords.y - program->cords.y1))
    {
        /*if (!program->map.own_color && !reset)
            color = get_color(isome, x, y, x1, y1);*/
        if ((program->cords.x > 0 && program->cords.x < program->window_x_size) && (program->cords.y > 0 && program->cords.y < program->window_y_size))
            my_mlx_pixel_put(program, program->cords.x, program->cords.y, color);
        program->cords.x += x_next;
        program->cords.y += y_next;
    }
}

void    ft_cords(t_program *program, float x, float y, float x1, float y1)
{
    program->cords.x = x;
    program->cords.y = y;
    program->cords.x1 = x1;
    program->cords.y1 = y1;
    program->cords.z = program->map.map[(int)y][(int)x];
    program->cords.z1 = program->map.map[(int)y1][(int)x1];
}

void ft_trace_pixel(t_program *program, int reset)
{
    int x;
    int y;

    y = 0;
    printf("llega\n");
    while (y < program->map.y_count)
    {
        x = 0;
        while (x < program->map.x_count)
        {
            if (x < program->map.x_count - 1)
                {ft_cords(program, x, y, x + 1, y);
                ft_draw_line(program, reset);}
                //ft_draw_line(x, y, x + 1, y, program, reset);
            if (y < program->map.y_count - 1)
                {ft_cords(program, x, y, x, y + 1);
                 ft_draw_line(program, reset);}
                //ft_draw_line(x, y, x, y + 1, program, reset);
            ++x;
        }
        ++y;
    }
}
















int	ft_set_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if ((str[0] != '0' || str[1] != 'x') || (
			(str[0] == '0' && str[1] == 'x') && (str[2] == '\0')))
		err_ctrl("Error: wrong color format\n", 3);
	
	if (ft_strlen(str) == 4)
	{
		r = ft_convert_hexa('0', '0');
		g = ft_convert_hexa('0', '0');
		b = ft_convert_hexa(str[2], str[3]);
	}
	else if (ft_strlen(str) == 6)
	{
		r = ft_convert_hexa('0', '0');
		g = ft_convert_hexa(str[2], str[3]);
		b = ft_convert_hexa(str[4], str[5]);
	}
	else
	{
		r = ft_convert_hexa(str[2], str[3]);
		g = ft_convert_hexa(str[4], str[5]);
		b = ft_convert_hexa(str[6], str[7]);
	}
	return (r << 16 | g << 8 | b);
}