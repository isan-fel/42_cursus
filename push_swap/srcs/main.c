/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:54:42 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 20:15:37 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	exit (0);
    return (1);
}

void    parse_numbers(char *argv)
{
    char    **aux_num;
    int     i;
    /*necesary to declare long to avoid error of max_int and min_int*/
    long    num;

    i = -1;
    aux_num = ft_split(argv, ' ');
    while (aux_num[++i])
    {
        if(!ft_atoi(aux_num[i]) && ft_strlen(aux_num[i]) != 1)
            err_ctrl("Error: wrong number in the stack", 1);
        num = ft_atoi(aux_num[i]);
        printf("num:%ld\n", num);
        /*ya me recoge los numeros, ahora tengo que ver como meterlos en una lista*/
    }
    free (aux_num);
}

int main(int argc, char **argv)
{
    //t_program program;
    
    int n;

    n = 0;
    if (argc < 2)
        return (err_ctrl("Error: more than valid arguments ; try like: ./push_swap list_of_number", 1));
    while (++n < argc)
    {
        parse_numbers(argv[n]);
    }
    return  (0);
}
