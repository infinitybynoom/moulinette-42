#include <stdio.h>
#include "ft_point.h"

int	main(void)
{
	t_point	point;

	point.x = 42;
	point.y = 21;
	printf("%d %d\n", point.x, point.y);
	return (0);
}
