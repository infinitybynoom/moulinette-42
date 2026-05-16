#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

static int	cmp_asc(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	tab1[4] = {1, 2, 3, 4};
	int	tab2[4] = {4, 3, 2, 1};
	int	tab3[4] = {1, 3, 2, 4};

	printf("%d\n", ft_is_sort(tab1, 4, cmp_asc));
	printf("%d\n", ft_is_sort(tab2, 4, cmp_asc));
	printf("%d\n", ft_is_sort(tab3, 4, cmp_asc));
	return (0);
}
