/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/29 18:28:28 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int		out_read;
	char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	line = NULL;
	printf("fd: %d\n", fd);
	printf("buffer_size: %d\n", BUFFER_SIZE);
	/*while (true)
	{*/
		out_read = read(fd, buf, BUFFER_SIZE);
		if (out_read < 0)
			return (-1);
		printf("out_read: %d\n", out_read);
		printf("buffer: %s\n", buf);
		//line = ft_split(buf, '\n');
	//}
	int n = 1;
	int i = 0;
	int x = 0;
	while (n != 0)
	{
		n = ft_strchr(buffer, '\n');
		if (n != 0)
		{
			line[x] = ft_substr();
			++x;
		}
	}
	while (line)
	{	
	printf("%s\n", line[n]);
	/*printf("%s\n", line[1]);
	printf("%s\n", line[2]);
	printf("%s\n", line[3]);
	*/
	++n;
	}
	return (out_read);
}
