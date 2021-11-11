/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:26:38 by isan-fel          #+#    #+#             */
/*   Updated: 2021/11/11 16:43:14 by isan-fel         ###   ########.fr       */
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
	while (++i < p->map.y_count)
		{
		free(p->map.map[i]);
		free(p->map.map_color[i]);
		}
	free(p->map.map);
	free(p->map.map_color);
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
	mlx_put_image_to_window(p->mlx, p->window, p->img.image, 0, 0);
	//ESC key
	if (key == 53)
		return(ft_close(p));
	//right row key
	if (key == 124)
		p->map.shift += 10;
	//change zoom
	if (key == 126)
		p->map.zoom += 2;
	if (key == 125)
		p->map.zoom -= 2;
	//altitude zoom
	if (key == 69)
		p->map.alt_zoom += 2;
	if (key == 78)
		p->map.alt_zoom -= 2;
	ft_trace_pixel(p, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->img.image, 0, 0);
    return(0);
}

int ft_key_linux_pressed(int key, t_program *p)
{
    printf("%d\n", key);
	//reset pixel to black
	ft_trace_pixel(p, 1);
	mlx_put_image_to_window(p->mlx, p->window, p->img.image, 0, 0);
	//ESC key
	if (key == 65307)
		return(ft_close(p));
	//right row key
	if (key == 65363)
		p->map.shift += 10;
	//change zoom
	if (key == 65362)
		p->map.zoom += 2;
	if (key == 65364)
		p->map.zoom -= 2;
	//altitude zoom
	if (key == 43)
		p->map.alt_zoom += 2;
	if (key == 45)
		p->map.alt_zoom -= 2;
	//mlx_clear_window(program->mlx, program->window);
	//put new image
	ft_trace_pixel(p, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->img.image, 0, 0);
    return(0);
}


float ft_min_int(float i, float j)
{
    if (i < j)
        return(i);
    return(j);
}

void	ft_rescaling_size(t_program *p)
{
	p->map.alt_zoom = 1;
	//program->map.zoom = ft_min_int((int) program->window_x_size/program->map.x_count, (int)program->window_y_size/program->map.y_count);
	//printf("zoom:%d\n", program->map.zoom);
	p->map.shift = 800;
	if (p->map.x_count <= 30)
		p->map.zoom = 40;
	else if (p->map.x_count > 30 && p->map.x_count < 100)
		p->map.zoom = 20;
	else if (p->map.x_count >= 100 && p->map.x_count < 200)
		p->map.zoom = 10;
	else if (p->map.x_count >= 200 && p->map.x_count < 300)
	{
		p->map.zoom = 6;
		p->map.shift = 900;
	}
	else
	{
		p->map.zoom = 2;
		p->map.shift = 700;
	}
}

void	leak(void)
{
	system("leaks fdf");
}

int		main(int argc, char **argv)
{
	int fd;
	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program p;

	atexit(leak);
	p.window_x_size = 2048;
	p.window_y_size = 1080;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//if (fd < 0 || !read_file(fd, &map))
		if (fd != 3)
			return (err_ctrl("error: invalid file", fd));
		//parsing the map
		ft_map(fd, argv[1], &p);
		//initialiting windows
		// mlx function that initialize the mlx and returns a pointer to it.
		p.mlx = mlx_init();
		// Open a window (window.c whitin this project)
		p.window = mlx_new_window(p.mlx, p.window_x_size, p.window_y_size, "FDF");
   		//initialize the image
		p.img.image = mlx_new_image(p.mlx, p.window_x_size, p.window_y_size);
		p.img.pixels = mlx_get_data_addr(p.img.image, &p.img.bits_per_pixel, &p.img.line_size, &p.img.endian);
		//initiate zoom and shift taking into account map size
    	ft_rescaling_size(&p);
		//create map image
		ft_trace_pixel(&p, 0);
		mlx_put_image_to_window(p.mlx, p.window, p.img.image, 0, 0);
		// hook the input() (hooks.c) function to the the key pressed event
    	//mlx_key_hook(program.window, ft_key_pressed, &program);
		mlx_key_hook(p.window, ft_key_pressed, &p);
		// mlx constant loop that keeps the detects the events
		mlx_loop(p.mlx);
		return(0);
	}
	else
		return (err_ctrl("error: more than 1 argument", 0));
}
