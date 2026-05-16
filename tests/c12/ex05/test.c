#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_push_params(t_list **begin_list, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_list	*list = NULL;
	t_list	*tmp;

	ft_list_push_params(&list, argc, argv);
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
