#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list **begin_list2,
		int (*cmp)());

static t_list	*make_elem(void *data)
{
	t_list	*e = malloc(sizeof(t_list));
	if (!e)
		return (NULL);
	e->data = data;
	e->next = NULL;
	return (e);
}

static void	push_back(t_list **begin, void *data)
{
	t_list	*e = make_elem(data);
	t_list	*tmp;

	if (!e)
		return ;
	if (!*begin)
	{
		*begin = e;
		return ;
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = e;
}

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int		a = 1, b = 3, c = 5, d = 2, e = 4;
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	t_list	*tmp;

	push_back(&list1, &a);
	push_back(&list1, &b);
	push_back(&list1, &c);
	push_back(&list2, &d);
	push_back(&list2, &e);
	ft_sorted_list_merge(&list1, &list2, cmp_int);
	printf("list2 empty: %s\n", list2 ? "no" : "yes");
	tmp = list1;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
