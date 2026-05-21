#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_reverse_fun(t_list **begin_list);

static t_list	*make_elem(void *data)
{
	t_list	*e = malloc(sizeof(t_list));
	if (!e)
		return (NULL);
	e->data = data;
	e->next = NULL;
	return (e);
}

static void	push_front(t_list **begin, void *data)
{
	t_list	*e = make_elem(data);
	if (!e)
		return ;
	e->next = *begin;
	*begin = e;
}

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;
	t_list	*tmp;

	push_front(&list, &c);
	push_front(&list, &b);
	push_front(&list, &a);
	ft_list_reverse_fun(&list);
	tmp = list;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
