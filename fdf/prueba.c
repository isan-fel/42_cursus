void ft_map(int fd, char *argv, t_program *p)
{
    char	*line;
	int		ret;
    int     n;
    
    n = -1;
    ret = get_next_line(fd, &line);
    /*for linux*/
    p->m.y_count = 0;
    p->m.x_count = 0;
    p->m.y_count = p->m.y_count + 1;
    /*for mac*/
    //program->map.y_count += 1;
    if (!line)
        err_ctrl("error: empty file", fd);
    while (line[++n])
    {
        if (line[n] == ',')
            p->m.own_color = 1;
    }
    n = -1;
    while (line[++n])
    {
        if (line[n] != ' ' && (line[n + 1] == '\n' || line[n + 1] == '\0' || line[n + 1] == ' '))
                p->m.x_count = p->m.x_count + 1;
            /*for mac*/
            //program->map.y_count += 1;
    }
    while (ret >= 0)
    {
        free(line);
		line = NULL;
        if (ret == 0)
			break ;
        ret = get_next_line(fd, &line);
        if (line[0] == '\n' || line[0] == '\0')
			{
                free(line);
                break ;
            }
        p->m.y_count = p->m.y_count + 1;
    }
    printf("x_len:%d\n", p->m.x_count);
    printf("y_len:%d\n", p->m.y_count);
    close(fd);
    ft_parse_aux_map(open(argv, O_RDONLY), p);
    ft_parse_map(p);
}