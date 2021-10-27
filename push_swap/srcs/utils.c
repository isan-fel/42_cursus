/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:40:35 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/27 11:09:29 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew_stack(void *content, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(aux, content, size);
	//printf("lst:%d\n", (int)aux);
	stack->content = aux;
	stack->next = NULL;
	return (stack);
}

void	ft_del_lstfirst(t_list **src)
{
	t_list	*aux;

	aux = *src;
	*src = aux->next;
	free(aux->content);
	free(aux);
}