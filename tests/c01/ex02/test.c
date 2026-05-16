#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 10; b = 20;
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);
	a = -5; b = 0;
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);
	return (0);
}
