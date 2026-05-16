#include <stdio.h>

int	ft_any(int *tab, int length, int (*f)(int));

static int	is_even(int n)
{
	return (n % 2 == 0);
}

int	main(void)
{
	int	tab1[3] = {1, 3, 5};
	int	tab2[3] = {1, 2, 3};

	printf("%d\n", ft_any(tab1, 3, is_even));
	printf("%d\n", ft_any(tab2, 3, is_even));
	return (0);
}
