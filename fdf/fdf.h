/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:23:06 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 20:22:57 by isan-fel         ###   ########.fr       */
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
	//int		z;
}	t_map;

/* vector with an x and y */
/*typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;
*/
/* A pointer to the window and its size */
/*typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;*/

/* all info needed for an image */
typedef struct	s_image {
	void		*img;
	char		*px;
	int			bxpx;
	int			l_sz;
	int			endian;
}				t_image;

/* The 4 values that define a color */
/*typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;
*/
typedef struct	s_program {
	void		*mlx;
	void		*window;
	int			win_x_size;
	int			win_y_size;
	t_image		i;
	t_map		m;
}				t_program;

//t_window	ft_new_window(void *mlx, int widht, int height, char *name);
/*t_image		ft_new_sprite(void *mlx, char *path);

t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);

int			ft_input(int key, void *program);
int			ft_update (void *param);
*/
float	max_i(float i, float j);
float	mod_int(float i);
int    ft_cords(t_program *p, int z1);
int ft_color(t_program *p, int z, int z1);
void    ft_map_color(t_program *p, float x, float y);
int		get_next_line(int fd, char **line);
void	ft_map(int fd, char *argv, t_program *p);
int		err_ctrl(char *reason, int fd);
void 	ft_trace_pixel(t_program *p, int reset);
int		ft_close(t_program *p);
int		get_color(int z, int z1, t_program *p);
int		ft_set_color(char *str);

# endif