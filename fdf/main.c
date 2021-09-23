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
	ft_trace_pixel(program);
	mlx_put_image_to_window(program->mlx, program->window, program->img.image, 0, 0);
    return(0);
}

/*void	leak(void)
{
	system("leaks fdf");
}*/

int		main(int argc, char **argv)
{
	int fd;
	t_map map;
	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program program;

	//atexit(leak);
	program.map.zoom = 40;
	program.map.shift = 350;
	program.map.alt_zoom = 1;
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
		program.window = mlx_new_window(program.mlx, 2048, 1080, "FDF");
   		//initialize the image
		program.img.image = mlx_new_image(program.mlx, 2048, 1080);
		program.img.pixels = mlx_get_data_addr(program.img.image, &program.img.bits_per_pixel, &program.img.line_size, &program.img.endian);
		// hook the input() (hooks.c) function to the the key pressed event
    	ft_trace_pixel(&program);
		mlx_put_image_to_window(program.mlx, program.window, program.img.image, 0, 0);
		// hook the input() (hooks.c) function to the the key pressed event
    	mlx_key_hook(program.window, ft_key_pressed, &program);
		// mlx constant loop that keeps the detects the events
		mlx_loop(program.mlx);
		//system("leaks fdf");
		return(0);
	}
	else
		return (err_ctrl("error: more than 1 argument", 0));
}
