#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)());

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

static void	print_data(void *data)
{
	printf("%d\n", *(int *)data);
}

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int		a = 1, b = 2, c = 3, d = 2;
	t_list	*list = NULL;

	push_front(&list, &d);
	push_front(&list, &c);
	push_front(&list, &b);
	push_front(&list, &a);
	ft_list_foreach_if(list, print_data, &b, cmp_int);
	return (0);
}
