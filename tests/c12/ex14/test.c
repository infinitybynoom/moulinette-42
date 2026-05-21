#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)());

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

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int		a = 3, b = 1, c = 2;
	t_list	*list = NULL;
	t_list	*tmp;

	push_front(&list, &a);
	push_front(&list, &b);
	push_front(&list, &c);
	ft_list_sort(&list, cmp_int);
	tmp = list;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
