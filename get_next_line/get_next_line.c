/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/10 12:24:25 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	save_line(char **stack, int fd, char **line)
{
	char	*mid_line;
	char	*temp;

	mid_line = ft_strchr(stack[fd], '\n');
	if (!mid_line)
	{
		*line = ft_strdup(stack[fd]);
		free(stack[fd]);
	}
	else
	{
		*mid_line = '\0';
		temp = ft_strdup(mid_line + 1);
		*line = ft_strdup(stack[fd]);
		free(stack[fd]);
		stack[fd] = temp;
	}
}

int get_next_line(int fd, char **line)
{
	int		out_read;
	char	buf[BUFFER_SIZE + 1];
	/*en linux no se llaman igual las variables de limits.h ; en linux: FOPEN_MAX ; en mac: OPEN_MAX*/
	//static char	*stack[FOPEN_MAX];
	static char	*stack[4096];
	char	*temp;

	out_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (out_read > 0)
	{
		out_read = read(fd, buf, BUFFER_SIZE);
		//printf("out_read: %d\n", out_read);
		if (out_read < 0)
			return (-1);
		if (out_read == 0)
		{
			*line = NULL;
			return (0);	
		}
		buf[out_read] = '\0';
		if (!stack[fd])
			stack[fd] = ft_calloc(1,1);
		temp = ft_strjoin(stack[fd], buf);
		stack[fd] = temp;
		//printf("stack: %s\n", stack[fd]);
		if (ft_strchr(stack[fd], '\n'))
		{
			//printf("entra if break\n");
			break ;
		}
	}
	save_line(stack, fd, line);
	return (1);
}
