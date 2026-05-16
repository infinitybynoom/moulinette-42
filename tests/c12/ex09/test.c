#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

static void	print_data(void *data)
{
	printf("%d ", *(int *)data);
}

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;

	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &a);
	ft_list_foreach(list, print_data);
	printf("\n");
	return (0);
}
