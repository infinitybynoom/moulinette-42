#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 10; b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d\n", a, b);
	a = 42; b = 6;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d\n", a, b);
	return (0);
}
