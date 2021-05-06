/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:05:37 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/06 18:50:31 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main (int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		n;

	n = 1;
	line = NULL;
	//printf("numero argumentos: %d\n", argc);
	while (n < argc)
	{
		//printf("argumento: %s\n", argv[n]);
		fd = open(argv[n], O_RDONLY);
		if (fd == -1)
			return (-1);
		//while (get_next_line(fd, &line))
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		printf("retorno funcion: [%d]  ;  Linea-->>%s\n", get_next_line(fd, &line), line);
		++n;
	}
	return (0);
}
