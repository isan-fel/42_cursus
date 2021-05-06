/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/06 13:35:23 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int		out_read = 1;
	char	buf[BUFFER_SIZE + 1];
	static char	*aux[4096];
	char	*mid_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	int n = 0;
	//int i = 0;
	//int x = 0;
	while (out_read > 0)
	{
		out_read = read(fd, buf, BUFFER_SIZE);
		if (out_read < 0)
			return (-1);
		buf[out_read] = '\0';
		printf("out_read: %d\n", out_read);
		printf("buffer: %s\n", buf);
		n = ft_intchr(buf, '\n');
		printf("n: %d\n", n);
		printf("aux antes if: %s\n", aux[fd]);
		//printf("mid_line antes if: %s\n", mid_line);
		if (aux[fd])
		{
			printf("entra if\n");
			//printf("mid_line antes join: %s\n", mid_line);
			aux[fd] = ft_strjoin(mid_line, buf);
			//free(aux[fd]);
			//aux[fd] = ft_strdup(mid_line);
			//aux[fd] = mid_line;
		}
		else
			aux[fd] = ft_strdup(buf);
		printf("aux: %s\n", aux[fd]);
		if (n != 0)
		{
			//line[x] = ft_substr(aux[fd], 0, n);
			*line = ft_substr(aux[fd], 0, n);
			//free (mid_line);
			mid_line = ft_strchr(buf, '\n');
			//*mid_line++ = '\0';
			//mid_line = aux[fd];
		}
		//free(aux[fd]);
		printf("linea: %s\n", *line);
		printf("mid_line: %s\n", mid_line);
		printf("aux: %s\n", aux[fd]);
		printf("buf: %s\n", buf);
		//++x;
	}
	//free(aux[fd]);
	return (out_read);
}
