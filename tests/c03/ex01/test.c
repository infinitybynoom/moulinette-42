#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	dst[64] = "Hello, ";

	ft_strncat(dst, "42 world", 2);
	printf("%s\n", dst);
	return (0);
}
