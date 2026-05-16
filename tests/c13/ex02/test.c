#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c12/ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)(void *, void *));

static void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}

static int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_list	*list = NULL;

	ft_list_push_front(&list, "c");
	ft_list_push_front(&list, "b");
	ft_list_push_front(&list, "a");
	ft_list_push_front(&list, "b");
	ft_list_foreach_if(list, print_data, "b", cmp_str);
	return (0);
}
