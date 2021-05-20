/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:08:27 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/20 19:01:08 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strdel(char **clean)
{
	if (clean)
	{
		free(*clean);
		*clean = NULL;
	}
}

int	save_line(char **stack, int fd, char **line)
{
	char	*mid_line;
	char	*temp;

	mid_line = ft_strchr(stack[fd], '\n');
	if (!mid_line)
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	else
	{
		*mid_line = '\0';
		temp = ft_strdup(mid_line + 1);
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
		stack[fd] = temp;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			out_read;
	char		buf[BUFFER_SIZE + 1];
	static char	*stack[4096];
	char		*temp;

	out_read = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 1 || out_read < 0)
		return (-1);
	if (!stack[fd])
		stack[fd] = ft_strdup("");
	while (out_read > 0)
	{
		buf[out_read] = '\0';
		temp = ft_strjoin(stack[fd], buf);
		free(stack[fd]);
		stack[fd] = temp;
		if (ft_strchr(buf, '\n') || ft_strrchr(stack[fd], '\n'))
			break ;
		out_read = read(fd, buf, BUFFER_SIZE);
	}
	return (save_line(stack, fd, line));
}
