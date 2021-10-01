/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:26:38 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/23 20:13:08 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	return (1);
}

int	ft_close(t_program *program)
{
	int i;
	int j;

	/*i = -1;
	while (++i < program->map.y_count)
	{
		j = -1;
		while (++j < program->map.x_count)
			free (program->map.map[i][j]);
	}*/
	//free (program->map.map);
	mlx_destroy_window(program->mlx, program->window);
	exit(0);
	//return(1);
}

int ft_key_pressed(int key, t_program *program)
{
    printf("%d\n", key);
	//ESC key
	if (key == 53)
		return(ft_close(program));
	//right row key
	if (key == 124)
		program->map.shift += 10;
	//change zoom
	if (key == 126)
		program->map.zoom += 2;
	if (key == 125)
		program->map.zoom -= 2;
	//altitude zoom
	if (key == 69)
		program->map.alt_zoom += 2;
	if (key == 78)
		program->map.alt_zoom -= 2;
	mlx_clear_window(program->mlx, program->window);
	ft_trace_pixel(program, 0);
	mlx_put_image_to_window(program->mlx, program->window, program->img.image, 0, 0);
    return(0);
}

int ft_key_linux_pressed(int key, t_program *program)
{
    printf("%d\n", key);
	//reset pixel to black
	ft_trace_pixel(program, 1);
	mlx_put_image_to_window(program->mlx, program->window, program->img.image, 0, 0);
	//ESC key
	if (key == 65307)
		return(ft_close(program));
	//right row key
	if (key == 65363)
		program->map.shift += 10;
	//change zoom
	if (key == 65362)
		program->map.zoom += 2;
	if (key == 65364)
		program->map.zoom -= 2;
	//altitude zoom
	if (key == 43)
		program->map.alt_zoom += 2;
	if (key == 45)
		program->map.alt_zoom -= 2;
	//mlx_clear_window(program->mlx, program->window);
	//put new image
	ft_trace_pixel(program, 0);
	mlx_put_image_to_window(program->mlx, program->window, program->img.image, 0, 0);
    return(0);
}

/*void	leak(void)
{
	system("leaks fdf");
}*/

float ft_min_int(float i, float j)
{
    if (i < j)
        return(i);
    return(j);
}

void	ft_rescaling_size(t_program *program)
{
	program->map.alt_zoom = 1;
	//program->map.zoom = ft_min_int((int) program->window_x_size/program->map.x_count, (int)program->window_y_size/program->map.y_count);
	//printf("zoom:%d\n", program->map.zoom);
	if (program->map.x_count <= 30)
	{
		program->map.zoom = 40;
		program->map.shift = 800;
	}
	else if (program->map.x_count > 30 && program->map.x_count <= 100)
	{
		program->map.zoom = 20;
		program->map.shift = 800;
	}
	else if (program->map.x_count > 100 && program->map.x_count < 300)
	{
		program->map.zoom = 20;
		program->map.shift = 700;
	}
	else
	{
		program->map.zoom = 2;
		program->map.shift = 520;
	}
}

int		main(int argc, char **argv)
{
	int fd;
	t_map map;
	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program program;

	//atexit(leak);
	program.window_x_size = 2048;
	program.window_y_size = 1080;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//if (fd < 0 || !read_file(fd, &map))
		if (fd != 3)
			return (err_ctrl("error: invalid file", fd));
		//parsing the map
		ft_map(fd, argv[1], &program);
		//initialiting windows
		// mlx function that initialize the mlx and returns a pointer to it.
		program.mlx = mlx_init();
		// Open a window (window.c whitin this project)
		program.window = mlx_new_window(program.mlx, program.window_x_size, program.window_y_size, "FDF");
   		//initialize the image
		program.img.image = mlx_new_image(program.mlx, program.window_x_size, program.window_y_size);
		program.img.pixels = mlx_get_data_addr(program.img.image, &program.img.bits_per_pixel, &program.img.line_size, &program.img.endian);
		//initiate zoom and shift taking into account map size
    	ft_rescaling_size(&program);
		//create map image
		ft_trace_pixel(&program, 0);
		mlx_put_image_to_window(program.mlx, program.window, program.img.image, 0, 0);
		// hook the input() (hooks.c) function to the the key pressed event
    	//mlx_key_hook(program.window, ft_key_pressed, &program);
		mlx_key_hook(program.window, ft_key_linux_pressed, &program);
		// mlx constant loop that keeps the detects the events
		mlx_loop(program.mlx);
		//system("leaks fdf");
		return(0);
	}
	else
		return (err_ctrl("error: more than 1 argument", 0));
}
