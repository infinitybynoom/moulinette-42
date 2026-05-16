#include <stdio.h>

int	ft_count_if(int *tab, int length, int (*f)(int));

static int	is_pos(int n)
{
	return (n > 0);
}

int	main(void)
{
	int	tab[5] = {-1, 2, -3, 4, 5};

	printf("%d\n", ft_count_if(tab, 5, is_pos));
	return (0);
}
