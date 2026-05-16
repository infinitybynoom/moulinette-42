#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

static int	times_two(int n)
{
	return (n * 2);
}

int	main(void)
{
	int	tab[4] = {1, 2, 3, 4};
	int	*result;
	int	i;

	result = ft_map(tab, 4, times_two);
	i = 0;
	while (i < 4)
		printf("%d ", result[i++]);
	printf("\n");
	free(result);
	return (0);
}
