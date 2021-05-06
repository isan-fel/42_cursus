/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/06 18:50:28 by isan-fel         ###   ########.fr       */
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
	static char	*stack[OPEN_MAX];
	//char	*mid_line;
	char	*temp;

	out_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (out_read > 0)
	{
		out_read = read(fd, buf, BUFFER_SIZE);
		if (out_read < 0)
			return (-1);
		buf[out_read] = '\0';
		if (!stack[fd])
			stack[fd] = ft_calloc(1,1);
		temp = ft_strjoin(stack[fd], buf);
		stack[fd] = temp;
		//mid_line = ft_strchr(stack[fd], '\n');
		/*while (ft_strchr(stack[fd], '\n')
		{
			*line = save_line(stack[fd], fd, line);
		}*/
		//if (mid_line = ft_strchr(stack[fd], '\n'))
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	save_line(stack, fd, line);
	return (1);
}
