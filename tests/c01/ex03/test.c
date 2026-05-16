#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	d;
	int	m;

	ft_div_mod(10, 3, &d, &m);
	printf("%d %d\n", d, m);
	ft_div_mod(42, 6, &d, &m);
	printf("%d %d\n", d, m);
	ft_div_mod(7, 2, &d, &m);
	printf("%d %d\n", d, m);
	return (0);
}
