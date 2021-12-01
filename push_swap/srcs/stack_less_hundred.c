/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_less_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:20:59 by isan-fel          #+#    #+#             */
/*   Updated: 2021/12/01 19:08:50 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_three(t_list **a, t_list **b)
{
    /*With this case we have 5 posibilities*/
    int	n1;
	int	n2;
	int	n3;

	n1 = *(int *)(*a)->content;
	n2 = *(int *)(*a)->next->content;
	n3 = *(int *)(*a)->next->next->content;
    /*3 posibilities with 1 move*/
    if (n1 > n2 && n1 < n3)
        swap(a, 'a');
    if (n1 > n2 && n1 > n3 && n2 < n3)
        rotate(a, 'a');
    if (n1 < n2 && n1 > n3)
        rev_rotate(a, 'a');
    /*2 posibilities with 2 moves*/
    if (n1 < n2 && n1 < n3 && n2 > n3)
    {
        swap(a, 'a');
        rotate(a, 'a');
    }
    if (n1 > n2 && n2 > n3)
    {
        swap(a, 'a');
        rev_rotate(a, 'a');
    }  
}

void    push(t_list **src, t_list **dst, char c)
{
    if (*dst)
        ft_lstadd_front(dst, ft_lstnew_stack((*src)->content, sizeof(int)));
    else
        *dst = ft_lstnew_stack((*src)->content, sizeof(int));
    ft_del_lstfirst(src);
    if (c == 'a')
        write(1, "pa\n", 3);
    if (c == 'b')
        write(1, "pb\n", 3);
}

void    iter_five_order(t_list **a, t_list **b, int len)
{
    /*we need to pass the top two numbers of a to b*/
    printf("len_a:%d\n", ft_lstsize(*a));
    while (len-- > 3)
        push(a, b, 'b');
    /*with this we can sort stack a like with 3 numbers*/
    swap_three(a, b);
    push(b, a, 'a');
}

void swap_five(t_list **a, t_list **b, int len)
{
    t_list *aux;
    iter_five_order(a, b, len);
    /*now we nedd to pass the numbers in b to a*/
    //len = ft_lstsize(*b);
    len = ft_lstsize(*a);
    printf("len_a:%d\n", len);
    while (!ft_sorted_stack(a, len))
    {
        rotate(a, 'a');
        if (ft_sorted_stack(a, len))
            break ;
        iter_five_order(a, b, len);
    }
    len = ft_lstsize(*b);
    printf("len_b:%d\n", len);
    while (len--)
        push(b, a, 'a');
    //if (!ft_sorted_stack(a, ft_lstsize(*a)))
      //  rotate(a, 'a');
    /*aux = *a;
    while (aux)
    {printf("lst:%d\n", aux->content);
    aux = aux->next;}*/
}