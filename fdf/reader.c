/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:44:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 20:25:42 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void    ft_parse_map(t_program *p)
{
    int     i;
    int     j;
    char    **aux;
    char    *hex_color;

    i = -1;
    p->m.map = malloc(sizeof(int *) * (p->m.y_count));
    p->m.map_color = malloc(sizeof(int *) * (p->m.y_count));
    if (!p->m.map)
        err_ctrl("Error: Allocating memory error\n", 3);
    while (++i < p->m.y_count)
    {
        aux = ft_split(p->m.aux_map[i], ' ');
        free (p->m.aux_map[i]);
        p->m.map[i] = malloc(sizeof(int) * (p->m.x_count));
        p->m.map_color[i] = malloc(sizeof(int) * (p->m.x_count));
        if (!p->m.map[i])
            err_ctrl("Error: Allocating memory error\n", 3);
        j = -1;
        while (++j < p->m.x_count)
        {
            p->m.map[i][j] = atoi(aux[j]);
            if (p->m.own_color)
                {
                hex_color = ft_strdup(ft_strchr(aux[j], ',') + 1);
                p->m.map_color[i][j] = ft_set_color(hex_color);
                free(hex_color);
                }
            free(aux[j]);
        }
        free(aux);
    }
    free (p->m.aux_map[i]);
    free (p->m.aux_map);
}

void    ft_parse_aux_map(int fd, t_program *p)
{
    char	*line;
	int		ret;
    int     i;

    i = 0;
    p->m.aux_map = ft_calloc(p->m.y_count + 1, sizeof(char *));
    ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		p->m.aux_map[i++] = ft_strdup(line);
        //printf("%s\n", program->map.aux_map[i-1]);
        free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
    //program->map.aux_map[i] = NULL;
    close(fd);
}

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