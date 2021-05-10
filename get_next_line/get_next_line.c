/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/10 20:15:41 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		save_line(char **stack, int fd, char **line, int out_read)
{
	char	*mid_line;
	char	*temp;

	if (!stack[fd])
		*line = ft_strdup(stack[fd]);
	mid_line = ft_strchr(stack[fd], '\n');
	if (!mid_line)
	{
		*line = ft_strdup(stack[fd]);
		//free(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	else
	{
		*mid_line = '\0';
		temp = ft_strdup(mid_line + 1);
		*line = ft_strdup(stack[fd]);
		//free(stack[fd]);
		ft_strdel(&stack[fd]);
		stack[fd] = temp;
	}
	//printf("out_read: %d\n", out_read);
	if (!out_read)
		return (0);
	return(1);
}

int	invalid_fd(char **line)
{
	*line = NULL;
	return (-1);
}

int get_next_line(int fd, char **line)
{
	int		out_read;
	char	buf[BUFFER_SIZE + 1];
	/*en linux no se llaman igual las variables de limits.h ; en linux: FOPEN_MAX ; en mac: OPEN_MAX*/
	//static char	*stack[FOPEN_MAX];
	static char	*stack[4096];
	char	*temp;
	//el problema de invalid_fd es por el read que segun lo tengo no es nunca negativo. Deberia ponerlo fuera. Revisar!
	//printf("stack principo func: %s\n", stack[fd]);
	out_read = 1;
	//out_read = read(fd, buf, BUFFER_SIZE);
	//if (fd < 0 || BUFFER_SIZE < 1 || out_read < 0)
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!stack[fd])
		stack[fd] = ft_calloc(1, 1);
	//printf("stack principo func: %s\n", stack[fd]);
	while (out_read > 0)
	{
		if (ft_strrchr(stack[fd], '\n'))
			return (save_line(stack, fd, line, out_read));
		//printf("out_read: %d\n", out_read);
		if (out_read < 0)
		{
			ft_strdel(&stack[fd]);
			return (-1);
		}
		buf[out_read] = '\0';
		temp = ft_strjoin(stack[fd], buf);
		free(stack[fd]);
		stack[fd] = temp;
		//printf("stack: %s\n", stack[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
		//out_read = read(fd, buf, BUFFER_SIZE);
	}
	return (save_line(stack, fd, line, out_read));
}
