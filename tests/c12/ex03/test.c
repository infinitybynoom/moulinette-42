#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_last(t_list *begin_list);

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;
	t_list	*last;

	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &a);
	last = ft_list_last(list);
	printf("%d\n", *(int *)last->data);
	return (0);
}
