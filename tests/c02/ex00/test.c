#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	dst[64];

	ft_strcpy(dst, "Hello, 42!");
	printf("%s\n", dst);
	ft_strcpy(dst, "");
	printf("[%s]\n", dst);
	ft_strcpy(dst, "abc");
	printf("%s\n", dst);
	return (0);
}
