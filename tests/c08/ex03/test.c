#include <stdio.h>
#include "ft_div_mod.h"

int	main(void)
{
	int	d;
	int	m;

	DIV_MOD(10, 3, d, m);
	printf("%d %d\n", d, m);
	return (0);
}
