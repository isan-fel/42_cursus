/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:19:15 by isan-fel          #+#    #+#             */
/*   Updated: 2021/12/01 19:18:22 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap(t_list **swap, char c)
{
    void *aux_swap;

    aux_swap = (*swap)->content;
    /*importante! para dar valor a elementos de la lista hay que hacer así*/
    (*swap)->content = (*swap)->next->content;
    (*swap)->next->content = aux_swap;
    if (c == 'a')
        write(1, "sa\n", 3);
}

void    rotate(t_list **lst, char c)
{
    /*put first element at the end of list*/
    //printf("lst:%d\n", (int *)(*lst)->content);
    ft_lstadd_back(lst, ft_lstnew_stack((*lst)->content, sizeof(int)));
    /*we need to delete de space of first element in list to allow second element to be first*/
    ft_del_lstfirst(lst);
    if (c == 'a')
        write(1, "ra\n", 3);
}

void    rev_rotate(t_list **lst, char c)
{
    t_list *aux;

    aux = *lst;
    //aux = ft_lstlast(aux);  
    /*put last element the first of list*/
    while (aux->next->next)
		aux = aux->next;
    ft_lstadd_front(lst, ft_lstnew_stack(aux->next->content, sizeof(int)));
    free(aux->next->content);
	free(aux->next);
    /*make a NULL to close list where was the last element that now is first*/
	aux->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
}

