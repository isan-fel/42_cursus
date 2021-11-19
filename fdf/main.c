/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:26:38 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/19 15:02:51 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	return (1);
}

void	ft_free_map(t_program *p)
{
	int	i;

	i = -1;
	while (++i < p->m.y_count)
		{
		free(p->m.map[i]);
		free(p->m.map_color[i]);
		}
	free(p->m.map);
	free(p->m.map_color);
}

int	ft_close(t_program *p)
{
	ft_free_map(p);
	mlx_destroy_window(p->mlx, p->window);
	exit(0);
	return(1);
}

int ft_key_pressed(int key, t_program *p)
{
    printf("%d\n", key);
	//reset pixel to black
	ft_trace_pixel(p, 1);
	mlx_put_image_to_window(p->mlx, p->window, p->i.img, 0, 0);
	//ESC key
	if (key == 53)
		return(ft_close(p));
	//right row key
	if (key == 124)
		p->m.shift += 10;
	//change zoom
	if (key == 126)
		p->m.zoom += 2;
	if (key == 125)
		p->m.zoom -= 2;
	//altitude zoom
	if (key == 69)
		p->m.alt_zoom += 2;
	if (key == 78)
		p->m.alt_zoom -= 2;
	ft_trace_pixel(p, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->i.img, 0, 0);
    return(0);
}

int ft_key_linux_pressed(int key, t_program *p)
{
    printf("%d\n", key);
	//reset pixel to black
	ft_trace_pixel(p, 1);
	mlx_put_image_to_window(p->mlx, p->window, p->i.img, 0, 0);
	//ESC key
	if (key == 65307)
		return(ft_close(p));
	//right row key
	if (key == 65363)
		p->m.shift += 10;
	//change zoom
	if (key == 65362)
		p->m.zoom += 2;
	if (key == 65364)
		p->m.zoom -= 2;
	//altitude zoom
	if (key == 43)
		p->m.alt_zoom += 2;
	if (key == 45)
		p->m.alt_zoom -= 2;
	//mlx_clear_window(program->mlx, program->window);
	//put new image
	ft_trace_pixel(p, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->i.img, 0, 0);
    return(0);
}

void	ft_rescaling_size(t_program *p)
{
	p->m.alt_zoom = 1;
	p->m.shift = 800;
	if (p->m.x_count <= 30)
		p->m.zoom = 40;
	else if (p->m.x_count > 30 && p->m.x_count < 100)
		p->m.zoom = 20;
	else if (p->m.x_count >= 100 && p->m.x_count < 200)
		p->m.zoom = 10;
	else if (p->m.x_count >= 200 && p->m.x_count < 300)
	{
		p->m.zoom = 6;
		p->m.shift = 900;
	}
	else
	{
		p->m.zoom = 2;
		p->m.shift = 700;
	}
}

void	leak(void)
{
	system("leaks fdf");
}

int		main(int argc, char **argv)
{
	int fd;
	t_program p;

	p.win_x_size = 2048;
	p.win_y_size = 1080;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != 3)
			return (err_ctrl("error: invalid file", fd));
		ft_reader(fd, argv[1], &p);
		p.mlx = mlx_init();
		p.window = mlx_new_window(p.mlx, p.win_x_size, p.win_y_size, "FDF");
		p.i.img = mlx_new_image(p.mlx, p.win_x_size, p.win_y_size);
		p.i.px = mlx_get_data_addr(p.i.img, &p.i.bxpx, &p.i.l_sz, &p.i.endian);
    	ft_rescaling_size(&p);
		ft_trace_pixel(&p, 0);
		mlx_put_image_to_window(p.mlx, p.window, p.i.img, 0, 0);
		mlx_key_hook(p.window, ft_key_linux_pressed, &p);
		mlx_loop(p.mlx);
		return(0);
	}
	else
		return (err_ctrl("error: more than 1 argument", 0));
}
