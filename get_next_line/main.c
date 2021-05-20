/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:05:37 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/20 13:48:20 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main (int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		n;
	char	lineadress[66];

	n = 1;
	line = NULL;
	int j = 1;
	int i;
	while (n < argc)
	{
		fd = open(argv[n], O_RDONLY);
		if (fd == -1)
			return (-1);
		/*while (get_next_line(fd, &line))
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		*/
		while ((i = get_next_line(fd, &line)) > 0)
		{
			//printf("%d |%s\n", i, line);
			printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
			lineadress[j - 1] = *line;
			j++;
		}
		//printf("%d |%s\n", i, line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		free(line);
		close(fd);
		++n;
	}
	//system("leaks -fullContent  a.out");
	return (0);
}
/*
int main(){
    char    *line;
    int     fd;
    int     stat;
    fd = open("2.txt", O_RDONLY);
    stat = get_next_line(fd, &line);
    while (stat >= 0)
    {
        //printf("%s\n", line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
        free(line);
        line = NULL;
        if (stat == 0)
            break ;
        stat = get_next_line(fd, &line);
    }
    free(line);
    line = NULL;
    close(fd);
    system("leaks a.out");
    return (0);
}*/
