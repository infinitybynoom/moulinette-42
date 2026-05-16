#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dst[10] = "Hi";
	unsigned int	ret;

	ret = ft_strlcat(dst, " there!", 10);
	printf("[%s] ret=%u\n", dst, ret);
	return (0);
}
