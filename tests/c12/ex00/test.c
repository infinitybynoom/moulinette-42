#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);

int	main(void)
{
	int		val = 42;
	t_list	*elem;

	elem = ft_create_elem(&val);
	printf("%d\n", *(int *)elem->data);
	printf("%s\n", elem->next == NULL ? "NULL" : "not NULL");
	free(elem);
	return (0);
}
