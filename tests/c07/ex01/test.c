#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*r;
	int	i;

	r = ft_range(1, 5);
	i = 0;
	while (i < 4)
		printf("%d ", r[i++]);
	printf("\n");
	free(r);
	r = ft_range(5, 1);
	if (r == NULL)
		printf("NULL\n");
	else
		free(r);
	return (0);
}
