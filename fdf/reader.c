/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:44:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/02 20:06:42 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void    ft_parse_map(t_program *program)
{
    int     i;
    int     j;
    char    **aux;
    char    *hex_color;

    i = -1;
    program->map.z_max = 0;
    program->map.z_min = 0;
    program->map.map = malloc(sizeof(int *) * (program->map.y_count + 1));
    program->map.map_color = malloc(sizeof(int *) * (program->map.y_count + 1));
    if (!program->map.map)
        err_ctrl("Error: Allocating memory error\n", 3);
    while (++i < program->map.y_count)
    {
        aux = ft_split(program->map.aux_map[i], ' ');
        free (program->map.aux_map[i]);
        program->map.map[i] = malloc(sizeof(int) * (program->map.x_count + 1));
        program->map.map_color[i] = malloc(sizeof(float) * (program->map.x_count + 1));
        if (!program->map.map[i])
            err_ctrl("Error: Allocating memory error\n", 3);
        j = -1;
        while (++j < program->map.x_count)
        {
            program->map.map[i][j] = atoi(aux[j]);
            //printf("%3d", program->map.map[i][j]);
            if (program->map.own_color)
                {
                hex_color = ft_strdup(ft_strchr(aux[j], ',') + 1);
                program->map.map_color[i][j] = ft_set_color(hex_color);
                free(hex_color);
                //printf("%3x  ", program->map.map_color[i][j]);
                }
            program->map.z_max = (int) ft_max_int((float)program->map.z_max, (float)program->map.map[i][j]);
            program->map.z_min = (int) ft_min_int((float)program->map.z_min, (float)program->map.map[i][j]);
            free(aux[j]);
        }
        //printf("\n");
        free(aux[j]);
        free(aux);
    }
    free (program->map.aux_map[i]);
    free (program->map.aux_map);
}

void    ft_parse_aux_map(int fd, t_program *program)
{
    char	*line;
	int		ret;
    int     i;

    i = 0;
    program->map.aux_map = malloc(sizeof(char *) * (program->map.y_count + 1));
    ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		program->map.aux_map[i++] = ft_strdup(line);
        free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
    program->map.aux_map[i] = NULL;
    close(fd);
}

void ft_map(int fd, char *argv, t_program *program)
{
    char	*line;
	int		ret;
    int     n;
    
    n = -1;
    ret = get_next_line(fd, &line);
    /*for linux*/
    program->map.y_count = 0;
    program->map.x_count = 0;
    program->map.y_count = program->map.y_count + 1;
    /*for mac*/
    //program->map.y_count += 1;
    if (!line)
        err_ctrl("error: empty file", fd);
    while (line[++n])
    {
        if (line[n] == ',')
            program->map.own_color = 1;
    }
    n = -1;
    while (line[++n])
    {
        if (line[n] != ' ' && (line[n + 1] == '\n' || line[n + 1] == '\0' || line[n + 1] == ' '))
                program->map.x_count = program->map.x_count + 1;
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
        program->map.y_count = program->map.y_count + 1;
    }
    printf("x_len:%d\n", program->map.x_count);
    printf("y_len:%d\n", program->map.y_count);
    close(fd);
    ft_parse_aux_map(open(argv, O_RDONLY), program);
    ft_parse_map(program);
}