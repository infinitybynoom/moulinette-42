#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list **begin_list);

int	main(void)
{
	int		a = 1, b = 2;
	t_list	*list = NULL;

	ft_list_push_front(&list, &a);
	ft_list_push_front(&list, &b);
	ft_list_clear(&list);
	printf("%s\n", list == NULL ? "NULL" : "not NULL");
	return (0);
}
