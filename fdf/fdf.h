/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:23:06 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/19 15:24:22 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define BUFFER_SIZE 20

typedef struct s_map
{
	char	**aux_map;
	int		**map;
	int		x_count;
	int		y_count;
	int		zoom;
	int		shift;
	int		alt_zoom;
	int		own_color;
	int		**map_color;
	int		reset;
	float	x1;
	float	y1;
	int		color;
}	t_map;

/* all info needed for an image */
typedef struct	s_image {
	void		*img;
	char		*px;
	int			bxpx;
	int			l_sz;
	int			endian;
}				t_image;

typedef struct	s_program {
	void		*mlx;
	void		*window;
	int			win_x_size;
	int			win_y_size;
	t_image		i;
	t_map		m;
}				t_program;

float	max_i(float i, float j);
float	mod_int(float i);
int		ft_cords(t_program *p, int z1);
int		ft_color(t_program *p, int z, int z1);
void	ft_map_color(t_program *p, float x, float y);
int		get_next_line(int fd, char **line);
void	ft_reader(int fd, char *argv, t_program *p);
void	ft_parse_map(t_program *p);
void	ft_parse_aux_map(int fd, t_program *p);
int		err_ctrl(char *reason, int fd);
void	ft_trace_pixel(t_program *p, int reset);
int		ft_close(t_program *p);
int		get_color(int z, int z1, t_program *p);
int		ft_set_color(char *str);

# endif