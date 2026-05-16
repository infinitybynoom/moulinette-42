#include <stdio.h>
#include "ft_ultimate_div_mod.h"

int	main(void)
{
	int	a = 10;
	int	b = 3;

	ULTIMATE_DIV_MOD(a, b);
	printf("%d %d\n", a, b);
	return (0);
}
