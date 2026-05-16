#include <stdio.h>
#include <stdlib.h>
#include "../c12/ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_merge(t_list **begin_list1, t_list **begin_list2);

int	main(void)
{
	int		a = 1, b = 2, c = 3, d = 4;
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	t_list	*tmp;

	ft_list_push_front(&list1, &b);
	ft_list_push_front(&list1, &a);
	ft_list_push_front(&list2, &d);
	ft_list_push_front(&list2, &c);
	ft_list_merge(&list1, &list2);
	printf("%s\n", list2 == NULL ? "list2 NULL" : "list2 not NULL");
	tmp = list1;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return (0);
}
