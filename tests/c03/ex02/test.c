#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	dst[64] = "Hello, ";

	ft_strcat(dst, "42!");
	printf("%s\n", dst);
	return (0);
}
