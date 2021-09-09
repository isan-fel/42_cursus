/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:02 by isan-fel          #+#    #+#             */
/*   Updated: 2021/09/09 18:31:09 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_show_map(t_map *map)
{
    t_program program;
    
    // mlx function that initialize the mlx and returns a pointer to it.
	program.mlx = mlx_init();
	// Open a window (window.c whitin this project)
	program.window = ft_new_window(program.mlx, 1980, 1080, "Hello world!");
    // hook the input() (hooks.c) function to the the key pressed event
    //mlx_key_hook(program.window.reference, *ft_input, &program);
    // hook a function to the loop (it would be called each frame)
    //mlx_loop_hook(program.mlx, *ft_update, &program);
	// mlx constant loop that keeps the detects the events
	mlx_loop(program.mlx);
}