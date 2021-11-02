/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:50:43 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/27 21:06:04 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

t_list	*ft_lstnew_stack(void *content, size_t size);
void	ft_del_lstfirst(t_list **lst);
int ft_sorted_stack(t_list **a, int len);
void    swap(t_list **swap, char c);
void    rotate(t_list **lst, char c);
void    rev_rotate(t_list **lst, char c);
void    swap_three(t_list **a, t_list **b);
void    swap_five(t_list **a, t_list **b, int len);

void	ft_reverse_rotate(t_list **src, char rr);

#endif