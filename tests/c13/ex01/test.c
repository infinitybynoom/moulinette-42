#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c12/ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(void *, void *), void (*free_fct)(void *));

static int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*tmp;

	ft_list_push_front(&list, "c");
	ft_list_push_front(&list, "b");
	ft_list_push_front(&list, "a");
	ft_list_push_front(&list, "b");
	ft_list_remove_if(&list, "b", cmp_str, NULL);
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
