/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:23:06 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/09 18:23:19 by isan-fel         ###   ########.fr       */
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

# define BUFFER_SIZE 20

typedef struct s_map
{
	char	**aux_map;
	int		**map;
	int		x_count;
	int		y_count;
}	t_map;

int		get_next_line(int fd, char **line);
void	ft_map(int fd, char *argv, t_map *map);
int		err_ctrl(char *reason, int fd);
void    ft_show_map(t_map *map);

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);

t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);

int			ft_input(int key, void *program);
int			ft_update (void *param);

# endif