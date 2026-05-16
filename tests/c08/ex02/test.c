#include <stdio.h>
#include "ft_swap.h"

int	main(void)
{
	int	a = 10;
	int	b = 20;

	SWAP(a, b);
	printf("%d %d\n", a, b);
	return (0);
}
