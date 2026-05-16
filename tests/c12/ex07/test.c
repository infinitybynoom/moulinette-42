#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;
	t_list	*elem;

	ft_list_push_front(&list, &c);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &a);
	elem = ft_list_at(list, 0);
	printf("%d\n", *(int *)elem->data);
	elem = ft_list_at(list, 2);
	printf("%d\n", *(int *)elem->data);
	elem = ft_list_at(list, 5);
	printf("%s\n", elem == NULL ? "NULL" : "not NULL");
	return (0);
}
