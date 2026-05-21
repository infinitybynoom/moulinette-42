#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int		a = 1, b = 3, c = 2;
	t_list	*list = NULL;
	t_list	*tmp;

	ft_sorted_list_insert(&list, &a, cmp_int);
	ft_sorted_list_insert(&list, &b, cmp_int);
	ft_sorted_list_insert(&list, &c, cmp_int);
	tmp = list;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
