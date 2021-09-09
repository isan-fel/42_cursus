/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:44:12 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/09 17:35:26 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_parse_map(t_map *map)
{
    int     i;
    int     j;
    char    **aux;

    i = -1;
    map->map = malloc(sizeof(int *) * (map->y_count + 1));
    if (!map->map)
        err_ctrl("Error: Allocating memory error\n", 3);
    while (++i < map->y_count)
    {
        aux = ft_split(map->aux_map[i], ' ');
        map->map[i] = malloc(sizeof(int) * (map->x_count + 1));
        if (!map->map[i])
            err_ctrl("Error: Allocating memory error\n", 3);
        j = -1;
        while (++j < map->x_count)
        {
            map->map[i][j] = atoi(aux[j]);
            printf("%3d", map->map[i][j]);
        }
        printf("\n");
        free(aux);
    }
}

void    ft_parse_aux_map(int fd, t_map *map)
{
    char	*line;
	int		ret;
    int     i;

    i = 0;
    map->aux_map = malloc(sizeof(char *) * (map->y_count + 1));
    ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		map->aux_map[i++] = ft_strdup(line);
		printf("%s\n", map->aux_map[i -1]);
        free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
    map->aux_map[i] = NULL;
    close(fd);
}

void ft_map(int fd, char *argv, t_map *map)
{
    char	*line;
	int		ret;
    int     n;
    
    n = -1;
	ret = get_next_line(fd, &line);
    map->y_count += 1;
    if (!line)
        err_ctrl("error: empty file", fd);
    while (line[++n])
    {
        if (line[n] != ' ' && !ft_isalpha(line[n + 1]))
            map->x_count += 1;
    }
	while (ret >= 0)
    {
        free(line);
		line = NULL;
        if (ret == 0)
			break ;
        ret = get_next_line(fd, &line);
        map->y_count += 1;
    }
    printf("x_len:%d\n", map->x_count);
    printf("y_len:%d\n", map->y_count);
    close(fd);
    ft_parse_aux_map(open(argv, O_RDONLY), map);
    ft_parse_map(map);
}