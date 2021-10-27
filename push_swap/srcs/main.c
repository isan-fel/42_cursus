/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:54:42 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/27 10:47:24 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	exit (0);
    return (1);
}

void    add_end_list(int num, t_list **a)
{
    t_list *aux_stack;

    aux_stack = *a;
    while (aux_stack)
	{
		if (*(int *)aux_stack->content == num)
			err_ctrl("Error: repeated number in the stack", 1);
		aux_stack = aux_stack->next;
	}
	ft_lstadd_back(a, ft_lstnew_stack((void *)&num, sizeof(int)));
}

void    parse_numbers(char *argv, t_list **a)
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
        if (num >= INT_MAX || num <= INT_MIN)
            err_ctrl("Error: number is over Max o Min INT", 1);
        /*add the correct number at the of the stack a list*/
        add_end_list((int)num, a);
    }
    free (aux_num);
}

int ft_sorted_stack(t_list **a, int len)
{
    t_list  *aux;

    aux = *a;
    --len;/*to avoid compare with null in list*/
    while (len--)
    {
        /*importante! para recoger el valor del content en la lista hay que llamarlo como lo llamo aqui*/
        if (*(int *)aux->content > *(int *)aux->next->content)
            return (0);
        aux = aux->next;
    }
    return (1);
}

void    push_swap(t_list **a, t_list **b, int len)
{
    /*first: comprove if stack a is order*/
    if (ft_sorted_stack(a, len))
        err_ctrl("Error: stack is order", 1);
    if (len == 2)
        swap(a, 'a');
    if (len == 3)
        swap_three(a, b);
    if (len > 3 && len <= 5)
        swap_five(a, b, len);
    /*if list_len == 100*/
}

int main(int argc, char **argv)
{
    /*lists are useful here to change numbers order in stack instead of an array*/
    t_list  *a;
    t_list  *b;  
    int n;

    n = 0;
    /*initialize the 2 stack like a list*/
    a = NULL;
    b = NULL;
    if (argc < 2)
        return (err_ctrl("Error: more than valid arguments ; try like: ./push_swap list_of_number", 1));
    while (++n < argc)
        parse_numbers(argv[n], &a);
    push_swap(&a, &b, ft_lstsize(a));
    return  (0);
}
