/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:16:08 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/19 15:16:40 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_color_map(t_program *p, int i, int j, char *aux)
{
    char    *hex_color;

    hex_color = ft_strdup(ft_strchr(aux, ',') + 1);
    p->m.map_color[i][j] = ft_set_color(hex_color);
    free(hex_color);
}

void    ft_allocmem_line(t_program *p)
{
    p->m.map = malloc(sizeof(int *) * (p->m.y_count));
    p->m.map_color = malloc(sizeof(int *) * (p->m.y_count));
    if (!p->m.map || !p->m.map_color)
        err_ctrl("Error: Allocating memory error\n", 3);
}

void    ft_allocmem_xitem(t_program *p, int i)
{
    p->m.map[i] = malloc(sizeof(int) * (p->m.x_count));
    p->m.map_color[i] = malloc(sizeof(int) * (p->m.x_count));
    if (!p->m.map[i] || !p->m.map_color[i])
        err_ctrl("Error: Allocating memory error\n", 3);
}

void    ft_parse_map(t_program *p)
{
    int     i;
    int     j;
    char    **aux;

    i = -1;
    ft_allocmem_line(p);
    while (++i < p->m.y_count)
    {
        aux = ft_split(p->m.aux_map[i], ' ');
        free (p->m.aux_map[i]);
        ft_allocmem_xitem(p, i);
        j = -1;
        while (++j < p->m.x_count)
        {
            p->m.map[i][j] = atoi(aux[j]);
            if (p->m.own_color)
                ft_color_map(p, i, j, aux[j]);
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
        free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
    close(fd);
}