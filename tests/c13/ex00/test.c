#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c12/ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));

static int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*tmp;

	ft_list_push_front(&list, "cherry");
	ft_list_push_front(&list, "apple");
	ft_list_push_front(&list, "banana");
	ft_list_sort(&list, cmp_str);
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
