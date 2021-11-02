#include "../push_swap.h"

void	ft_del(t_list **src)
{
	t_list	*aux;

	aux = *src;
	*src = aux->next;
	free(aux->content);
	free(aux);
}

t_list	*ft_lstnew_struct(void *newcontent, size_t size)
{
	t_list	*new;
	void	*content;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	content = malloc(size);
	if (!content)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(content, newcontent, size);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_swap(t_list **src, char s)
{
	void	*aux;

	aux = (*src)->content;
	(*src)->content = (*src)->next->content;
	(*src)->next->content = aux;
	if (s == 'a')
		write(1, "sa\n", 3);
	else if (s == 'b')
		write(1, "sb\n", 3);
}


void	ft_rotate(t_list **src, char r)
{
	ft_lstadd_back(src, ft_lstnew_struct((*src)->content, sizeof(int)));
	ft_del(src);
	if (r == 'a')
		write(1, "ra\n", 3);
	else if (r == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **src, char rr)
{
	t_list	*aux;
	int		i;

	aux = *src;
	i = 1;
	while (aux->next->next)
	{
		aux = aux->next;
		i++;
	}
	ft_lstadd_front(src, ft_lstnew_struct(aux->next->content, sizeof(int)));
	free(aux->next->content);
	free(aux->next);
	aux->next = NULL;
	if (rr == 'a')
		write(1, "rra\n", 4);
	else if (rr == 'b')
		write(1, "rrb\n", 4);
}

