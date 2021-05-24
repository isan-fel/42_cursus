/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:15:47 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/27 12:32:58 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	pos = *lst;
	while (*lst)
	{
		pos = pos->next;
		ft_lstdelone(*lst, del);
		*lst = pos;
	}
	*lst = NULL;
}
