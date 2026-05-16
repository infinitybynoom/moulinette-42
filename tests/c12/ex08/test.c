#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_reverse(t_list **begin_list);

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;
	t_list	*tmp;

	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &a);
	ft_list_reverse(&list);
	tmp = list;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return (0);
}
