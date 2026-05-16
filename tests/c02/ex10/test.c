#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dst[10];
	unsigned int	ret;

	ret = ft_strlcpy(dst, "Hello, 42!", 10);
	printf("[%s] ret=%u\n", dst, ret);
	ret = ft_strlcpy(dst, "Hello", 10);
	printf("[%s] ret=%u\n", dst, ret);
	ret = ft_strlcpy(dst, "Hi", 0);
	printf("ret=%u\n", ret);
	return (0);
}
