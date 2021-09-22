/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:26:38 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/09 18:31:57 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	return (1);
}

int ft_deal_key(int key, void *program)
{
    printf("%d", key);
    return(0);
}

int		main(int argc, char **argv)
{
	int fd;
	t_map map;
	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program program;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//if (fd < 0 || !read_file(fd, &map))
		if (fd != 3)
			return (err_ctrl("error: invalid file", fd));
		//parsing the map
		ft_map(fd, argv[1], &map);
		//initialiting windows
		// mlx function that initialize the mlx and returns a pointer to it.
		program.mlx = mlx_init();
		// Open a window (window.c whitin this project)
		program.window = mlx_new_window(program.mlx, 1000, 1000, "FDF");
   		// hook the input() (hooks.c) function to the the key pressed event
    	ft_trace_pixel(&program, &map);
    	// hook a function to the loop (it would be called each frame)
    	mlx_key_hook(program.window, ft_deal_key, NULL);
		// mlx constant loop that keeps the detects the events
		mlx_loop(program.mlx);
	}
	else
		return (err_ctrl("error: more than 1 argument", 0));
	// ----------
/*
	// Create a new image/sprite (image.c)
	program.sprite = ft_new_sprite(program.mlx, "block.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	// mlx function that draws an image into a window at the given position
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);

	// ----------

	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(program.mlx, *ft_update, &program);

	// ----------

	// mlx constant loop that keeps the detects the events
	mlx_loop(program.mlx);*/
}
