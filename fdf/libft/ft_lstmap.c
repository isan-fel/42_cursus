/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:05:29 by isan-fel          #+#    #+#             */
/*   Updated: 2021/04/27 13:29:06 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*ini_nlst;

	if (!lst || !f)
		return (NULL);
	nlst = ft_lstnew(f(lst->content));
	if (!nlst)
		return (NULL);
	ini_nlst = nlst;
	lst = lst->next;
	while (lst)
	{
		nlst->next = ft_lstnew(f(lst->content));
		if (!nlst->next)
		{
			ft_lstclear(&ini_nlst, del);
			return (NULL);
		}
		lst = lst->next;
		nlst = nlst->next;
	}
	nlst->next = NULL;
	return (ini_nlst);
}
