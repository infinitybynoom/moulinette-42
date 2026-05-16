#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

static void	print_int(int n)
{
	printf("%d\n", n);
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, print_int);
	return (0);
}
