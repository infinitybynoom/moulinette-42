#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int	ft_list_size(t_list *begin_list);

int	main(void)
{
	int		a = 1, b = 2, c = 3;
	t_list	*list = NULL;

	printf("%d\n", ft_list_size(list));
	ft_list_push_front(&list, &a);
	ft_list_push_front(&list, &b);
	ft_list_push_front(&list, &c);
	printf("%d\n", ft_list_size(list));
	return (0);
}
