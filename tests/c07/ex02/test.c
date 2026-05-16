#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*r;
	int	ret;
	int	i;

	ret = ft_ultimate_range(&r, 1, 5);
	printf("ret=%d\n", ret);
	i = 0;
	while (i < ret)
		printf("%d ", r[i++]);
	printf("\n");
	free(r);
	ret = ft_ultimate_range(&r, 5, 1);
	printf("ret=%d\n", ret);
	return (0);
}
