#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list **begin_list2);

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
	int		a = 1, b = 2, c = 3, d = 4;
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	t_list	*tmp;

	push_front(&list1, &b);
	push_front(&list1, &a);
	push_front(&list2, &d);
	push_front(&list2, &c);
	ft_list_merge(&list1, &list2);
	printf("list2 empty: %s\n", list2 ? "no" : "yes");
	tmp = list1;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
